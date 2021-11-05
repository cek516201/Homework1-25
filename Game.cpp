#include "Game.h"
#include "TextureManager.h"
#include "Background.h"
#include "Sun.h"
#include "Player.h"
#include "Cloud.h"
#include "Star.h"
#include "InputHandler.h"

Game* Game::s_pInstance = 0;

bool Game::init(const char *title, int xpos, int ypos,  int width, int height, int flags) 
{
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
  {
    return false; // SDL 초기화 실패
  }

  m_pWindow = SDL_CreateWindow(title, xpos, ypos, width,height, flags);
  if (m_pWindow == 0)
  {
    return false; // 윈도우 생성 실패
  }

  m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
  if (m_pRenderer == 0)
  {
    return false; // 랜더러 생성 실패
  }

  if( TheTextureManager::Instance()->load("Assets/background.png", "background", m_pRenderer) == false )
  {
    return false; // 배경 이미지 로드 실패
  }

  if( TheTextureManager::Instance()->load("Assets/sun-alpha.png", "sun", m_pRenderer) == false )
  {
    return false; // 태양 이미지 로드 실패
  }

  if( TheTextureManager::Instance()->load("Assets/cat-alpha.png", "cat", m_pRenderer) == false )
  {
    return false; // 고양이 이미지 로드 실패
  }

  if( TheTextureManager::Instance()->load("Assets/cloud-alpha.png", "cloud", m_pRenderer) == false )
  {
    return false; // 구름 이미지 로드 실패
  }

  if( TheTextureManager::Instance()->load("Assets/maptile_space.png", "mapTileSpace", m_pRenderer) == false )
  {
    return false; // 맵 벽 로드 실패
  }

  if( TheTextureManager::Instance()->load("Assets/maptile_wall.png", "mapTileWall", m_pRenderer) == false )
  {
    return false; // 맵 공간 로드 실패
  }

  if( TheTextureManager::Instance()->load("Assets/star-alpha.png", "star", m_pRenderer) == false )
  {
    return false; // 별 이미지 로드 실패
  }

  m_gameObjects.push_back( new Background( new LoaderParams(0, 0, 640, 569, "background")));
  m_gameObjects.push_back( new Sun( new LoaderParams(450, 50, 160, 160, "sun")));
  m_gameObjects.push_back( new Player( new LoaderParams(200, 385, 128, 82, "cat")));
  m_gameObjects.push_back( new Cloud( new LoaderParams(100, 100, 96, 96, "cloud")));

  for(int y = 0 ; y < 19 ; y++)
  {
    for(int x = 0 ; x < 19 ; x++)
    {
      if(map[y][x] == 0)
      {
        m_gameObjects.push_back( new Background( new LoaderParams(640 - (19-x) * 10, 569 - (19-y) * 10, 10, 10, "mapTileSpace")));
      }
      else if(map[y][x] == 1)
      {
        m_gameObjects.push_back( new Background( new LoaderParams(640 - (19-x) * 10, 569 - (19-y) * 10, 10, 10, "mapTileWall")));
      }
    }
  }

  m_gameObjects.push_back( new Star( new LoaderParams(200, 200, 96, 96, "star")));

  m_bRunning = true;

  return true;
}

void Game::render()
{
  SDL_RenderClear(m_pRenderer);
  
  for(int i = 0 ; i < m_gameObjects.size() ; i++)
  {
    m_gameObjects[i]->draw();
  }
   
  SDL_RenderPresent(m_pRenderer);
}

void Game::update()
{
  for(int i = 0 ; i < m_gameObjects.size() ; i++)
  {
    m_gameObjects[i]->update();
  }
}

bool Game::running()
{ 
  return m_bRunning; 
}

void Game::handleEvents() 
{
  TheInputHandler::Instance()->update();
}

void Game::clean() 
{
  TheInputHandler::Instance()->clean();
  
  SDL_DestroyWindow(m_pWindow);
  SDL_DestroyRenderer(m_pRenderer);
  SDL_Quit();
}
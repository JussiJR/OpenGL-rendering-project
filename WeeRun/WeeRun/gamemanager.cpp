#include "gamemanager.h"


GameManager::GameManager(const char* path)
{
	//!		Initialized
	Initialized = 0;

	//!		Textures
	_mapTextures;
	_Textures;
	//!		Rendering
	_shader;
	_vertexArray;
	_indices;

	//!		Uniforms
	_viewMatrixUniform = 0;

	//!		Player	
	_haunted = 0;

	//!		Game settings
	_difficulty = 0;
	_gameMode = 0;

	//!		Counters
	_unixTimer = 0;
	_entityCount = 1;

	//!		Render settings
	_fieldOfView = 90;

	_currentChunk = 0;

	_yaw = 0.0f;

}

GameManager::~GameManager()
{
	//! Delete rendering stuff
	_vertexArray.Delete();
	_indices.Delete();
	_shader.Delete();

	//! Delete object stuff
	_mapData.Delete();
	_entityData.Delete();

	//!		Player	
	_haunted = 0;

	//!		Game settings
	_difficulty = 0;
	_gameMode = 0;

	//!		Counters
	_unixTimer = 0;
	_entityCount = 1;

	//!		Render settings
	_fieldOfView = 90;

	//!		Time scale
	Initialized = 0;
}

int GameManager::Update(int* errorc)
{
	return *errorc;
	return EXIT_SUCCESS;
}

int GameManager::FixedUpdate(int* errorc)
{

	return *errorc;
	return EXIT_SUCCESS;
}

int GameManager::Render(int* errorc,int render_distance)
{
	_shader.Activate(); // not very optimized tho lol :D all tho it is only one and this is securest one XDDD 



	return *errorc;
	return EXIT_SUCCESS;

}
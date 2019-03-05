#pragma once

static constexpr int k_windowHeight { 720 };
static constexpr int k_windowWidth { 480 };
static constexpr int k_windowMin{ 0 };
static constexpr int k_shipChoices{ 2 };
static constexpr int k_shipWidth { 75 };
static constexpr int k_shipHeight { 75 };

static constexpr int k_playerSpawnY{ k_windowHeight - (2 * k_shipHeight) };
static constexpr int k_playerSpawnX{ (k_windowWidth/2) - (k_shipWidth/2) };
static constexpr int k_playerMoveSpeed{ 15 };
static constexpr int k_startingLife{ 3 };
static constexpr int k_playerDamaged = { 1 };

static const char* k_textFont = { "Assets/RobotoSlab-Regular.ttf" };
static const char* k_ship1 = {"Assets/ship1.png"};
static const char* k_ship2 = { "Assets/ship2.png" };
static const char* k_ship3 = { "Assets/ship3.png" };
static const char* k_wingman = { "Assets/Wingman.png" };
static const char* k_menu = { "Assets/menu.jpg" };
static const char* k_scrollingBackground = { "Assets/spacebackground.png" };
static const char* k_projectile = { "Assets/projectile.png" };
static const char* k_enemyprojectile = { "Assets/enemyprojectile.png" };
static const char* k_spider = { "Assets/spider.png" };
static const char* k_enemyShip = { "Assets/enemyship.png" };
static const char* k_fireSound = { "Assets/shipfire.wav" };

static const int k_projectileHeight = { 60 };
static const int k_projectileWidth = { 64 };
static const int k_playerProjSpeed = { -5 };
static const int k_enemyProjSpeed = { 4 };

static const int k_spiderDimension = { 35 };
static const int k_spiderDead = { 6 };
static const int k_startingAiHealth = { 1 };

static const int k_enemyShipWidth = { 75 };
static const int k_enemyShipHeight = { 126 };
static const int k_enemyShipSpeed = { 2 };
static const int k_spiderSpeed = { 3 };

static const char* k_rocket = { "Assets/Rocket.png" };
static const int k_rocketHeight = { 124 };
static const int k_rocketWidth = { 23 };
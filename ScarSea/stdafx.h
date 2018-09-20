#pragma once

#define SAFE_DELETE(x) if(x) {delete x; x = NULL;}
#define Vec2 D3DXVECTOR2
#define Matrix D3DXMATRIX

#include<Windows.h>
#include<stdio.h>
#include<d3d9.h>
#include<d3dx9.h>
#include<map>
#include<list>
#include<vector>
#include<string>
//
#include"Singleton.h"
#include"Input.h"
#include"Renderer.h"
#include"App.h"
#include"Object.h"
#include"ObjectMgr.h"
#include"CollisionMgr.h"
#include"SceneDirector.h"
#include"Sprite.h"
#include"Animation.h"
#include"Font.h"
#include"Gold.h"
#include"PlayerMgr.h"
#include"Bullet.h"
#include"Cannon.h"
#include"Enemy.h"
#include"Shop.h"
#include"Stage.h"

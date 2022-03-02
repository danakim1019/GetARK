// Copyright Epic Games, Inc. All Rights Reserved.

#include "GetArk.h"
#include "Modules/ModuleManager.h"

//언리얼 엔진은 특정 플랫폼에 종속적이지 않은 바이너리 제작을 위해 언리얼 빌드 툴이라는 도구를 사용해 빌드
//언리얼 엔진의 모든 소스는 모듈이라는 단위로 구성
//필요한 모듈을 타겟으로 묶어서, 최종 빌드를 만들어냄

//게임 제작에 사용되는 로직을 담은 기본 모듈을 주 게임 모듈이라고 함
//주 게임 말고도 다른 모듈들 추가 가능 IMPLEMENT_MODULE() 이요 

//주 게임 모듈임을 지정하는 모듈 매크로
//FDefaultGameModuleImpl : 이미 엔진에서 제공하고 있는 모듈 제작을 위한 제공하는 간단한 클래스
IMPLEMENT_PRIMARY_GAME_MODULE( FDefaultGameModuleImpl, GetArk, "GetArk" );

DEFINE_LOG_CATEGORY(LogGetArk)
 
//지정하고 나면 해당파일.Build.cs 파일을 이용해서 현재 모듈이 참조할 외부 모듈의 목록을 지정하는데 사용함
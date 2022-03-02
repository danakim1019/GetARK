// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GetArk : ModuleRules
{
	public GetArk(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		//Core, CoreUObject, Engine, InputCore 네 가지 모듈은 보통 잘 쓰임
        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "NavigationSystem", "AIModule" });
    }
}

//언리얼 빌드 툴에 의해서 소스 구조 파악은 되었지만, 빌드할 대상에 우리가 만든 모듈이 추가되지 않음
//그래서 프로젝트이름.Target.cs 파일에서 빌드할 대상 모듈을 지정함
// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GetArk : ModuleRules
{
	public GetArk(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		//Core, CoreUObject, Engine, InputCore �� ���� ����� ���� �� ����
        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "NavigationSystem", "AIModule" });
    }
}

//�𸮾� ���� ���� ���ؼ� �ҽ� ���� �ľ��� �Ǿ�����, ������ ��� �츮�� ���� ����� �߰����� ����
//�׷��� ������Ʈ�̸�.Target.cs ���Ͽ��� ������ ��� ����� ������
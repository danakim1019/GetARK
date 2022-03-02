// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class GetArkTarget : TargetRules
{
	public GetArkTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.Add("GetArk");
	}
}

//만약 모듈을 추가하려면 ExtraModulesNames.AddRange(new string[]{"GetArk","모듈이름"});으로 변경

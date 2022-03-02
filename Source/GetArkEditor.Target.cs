// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class GetArkEditorTarget : TargetRules
{
	public GetArkEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.Add("GetArk");
	}
}


//만약 모듈을 추가하려면 ExtraModulesNames.AddRange(new string[]{"GetArk","모듈이름"});으로 변경
// 그 후에 .uproject 파일 안에 모듈을 추가하라는 명령어를 추가해야함
//
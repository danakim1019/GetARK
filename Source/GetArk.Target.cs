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

//���� ����� �߰��Ϸ��� ExtraModulesNames.AddRange(new string[]{"GetArk","����̸�"});���� ����

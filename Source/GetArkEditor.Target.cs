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


//���� ����� �߰��Ϸ��� ExtraModulesNames.AddRange(new string[]{"GetArk","����̸�"});���� ����
// �� �Ŀ� .uproject ���� �ȿ� ����� �߰��϶�� ��ɾ �߰��ؾ���
//
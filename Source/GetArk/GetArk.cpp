// Copyright Epic Games, Inc. All Rights Reserved.

#include "GetArk.h"
#include "Modules/ModuleManager.h"

//�𸮾� ������ Ư�� �÷����� ���������� ���� ���̳ʸ� ������ ���� �𸮾� ���� ���̶�� ������ ����� ����
//�𸮾� ������ ��� �ҽ��� ����̶�� ������ ����
//�ʿ��� ����� Ÿ������ ���, ���� ���带 ����

//���� ���ۿ� ���Ǵ� ������ ���� �⺻ ����� �� ���� ����̶�� ��
//�� ���� ���� �ٸ� ���� �߰� ���� IMPLEMENT_MODULE() �̿� 

//�� ���� ������� �����ϴ� ��� ��ũ��
//FDefaultGameModuleImpl : �̹� �������� �����ϰ� �ִ� ��� ������ ���� �����ϴ� ������ Ŭ����
IMPLEMENT_PRIMARY_GAME_MODULE( FDefaultGameModuleImpl, GetArk, "GetArk" );

DEFINE_LOG_CATEGORY(LogGetArk)
 
//�����ϰ� ���� �ش�����.Build.cs ������ �̿��ؼ� ���� ����� ������ �ܺ� ����� ����� �����ϴµ� �����
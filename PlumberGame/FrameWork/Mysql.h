//#pragma once
//#include "Include.h"
//
//class Mysql
//{
//
//public:
//	Mysql();
//	~Mysql();
//
//	// MYSQL ����ü ���� (Logo é�Ϳ��� 1 �ܰ� �׽�Ʈ ���� Ȯ�ο�)
//	MYSQL mysql;
//
//	// MYSQL ���� �� ���� ����
//	MYSQL		*connection = NULL, conn;
//	MYSQL_RES	*sql_result;
//	MYSQL_ROW	sql_row;
//	int query_start;
//
//	// ����Ÿ ���̽� Į�� ���� ����
//	char name[4];
//	char score[80];
//	char query[255];
//
//	// MYSQL ���� ����
//	char state[256];
//	bool mysql_Success;
//
//	// MYSQL ��� Ȯ�� ����
//	char result[256];
//
//	void Init();
//	void Update(double frame);
//	void Draw();
//
//	//����Ÿ���̽��� ����
//	void save();
//};
//
//extern Mysql sql;
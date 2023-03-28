//#pragma once
//#include "Include.h"
//
//Mysql sql;
//
//
//Mysql::Mysql()
//{
//
//}
//
//Mysql::~Mysql()
//{
//	// mysql(데이타 베이스) 연결 해제
//	mysql_close(connection);
//}
//
//void Mysql::Init()
//{
//
//}
//
//void Mysql::Update(double frame)
//{
//
//
//}
//
//void Mysql::Draw()
//{
//	// 데이타 베이스 처리 상태 표시
//	if (sql.mysql_Success)
//	{
//		//dv_font.DrawString("Success", 500, 0);   
//	}
//	else
//	{
//		dv_font.DrawString("Error", 500, 0);   
//		dv_font.DrawString(sql.state, 700, 0);
//	}
//
//
//}
//
//void Mysql::save()
//{
//	
//	char temp[30];
//
//	_itoa(map.cleartime,temp,10);
//
//	sprintf_s(name, "%s", "asd");
//	sprintf_s(score, "%s", temp);
//
//
//
//	// 전달 할 쿼리값 셋팅
//	sprintf_s(query, "insert into %s values "
//		"(now(),'%s', '%s')", DB_TABLE, score, name);
//
//	//sprintf_s(query, "insert into PlumberGame values "
//	//	"(now(),'%s', '%s')", score, name);
//
//	// 쿼리문 전송
//	query_start = mysql_query(connection, query);
//	if (query_start != 0) // 전송 실패시
//	{
//		sprintf_s(state, "Mysql query error : %s", mysql_error(&conn));
//		sql.mysql_Success = false;
//	}
//	else // 성공시
//	{
//		mysql_Success = true;
//	}
//
//}

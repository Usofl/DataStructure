// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 또는 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>



// TODO: 프로그램에 필요한 추가 헤더는 여기에서 참조합니다.
#include <iostream>
#include <memory>

template<typename T>
inline std::shared_ptr<T> MakeArray(const unsigned int& _iSize)
{
	return std::shared_ptr<T>(new T[_iSize], [](T* p) { delete[] p; });
}
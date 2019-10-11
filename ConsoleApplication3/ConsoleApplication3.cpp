// ConsoleApplication3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <windows.h>
int main()
{
	int a,b=0;
	wchar_t s1[2] = L"​",s2[2]=L"‌",tmp[300],Path[255],path[300];
	GetModuleFileName(NULL, Path, MAX_PATH);//直接获取程序名

	(wcsrchr(Path, L'\\'))[1] = 0;
	wcscpy_s(path, Path);
	wcscat_s(path, L"example");
	path[wcslen(path) + 1] = '\0';
	path[wcslen(path) + 2] = '\0';
	scanf_s("%d", &a);
	for (int i = 1; i <= 10; ++i)
	{
		for (int j = 0; j < pow(2, i); ++j)
		{
			wcscpy_s(tmp, Path);
			for (int k = 1; k <= i; ++k)
				if ((j >> (k - 1)) % 2 == 0)wcscat_s(tmp, s1); else wcscat_s(tmp, s2);
			wcscat_s(tmp, L"回收站");
			for (int k = 1; k <= i; ++k)
				if ((j >> (k - 1)) % 2 == 0)wcscat_s(tmp, s1); else wcscat_s(tmp, s2);
			
			//MessageBox(0, path, 0, 0);//CreateDirectory(tmp, 0);
			SHFILEOPSTRUCT FileOp = {0};
			FileOp.fFlags = FOF_NOCONFIRMATION | FOF_RENAMEONCOLLISION;		//操作与确认标志 
			FileOp.hNameMappings = NULL;			//文件映射 
			FileOp.hwnd = NULL;						//消息发送的窗口句柄；
			FileOp.lpszProgressTitle = NULL;		//文件操作进度窗口标题 
			FileOp.pFrom = path;				//源文件及路径 
			FileOp.pTo = tmp;					//目标文件及路径 
			FileOp.wFunc = FO_COPY;					//操作类型 
			SHFileOperation(&FileOp);
		//	
		//	wcscat_s(tmp, L"\\1.ico");
		//	CopyFile(path, tmp,true);
		//	//copyf
		//	//MessageBox(0, path, 0, 0);
		//	(wcsrchr(tmp, L'\\'))[1] = 0;
		//	wcscat_s(tmp, L"desktop.ini");
		//WritePrivateProfileString(L".ShellClassInfo", L"IconResource", L"1.ico", tmp);
		//	SetFileAttributes(tmp,FILE_ATTRIBUTE_SYSTEM| FILE_ATTRIBUTE_HIDDEN);
		//	
			b++;
			if (b >= a)return 0;
		}
	}
	
    //std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

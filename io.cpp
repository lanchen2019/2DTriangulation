#include <string.h>
#include <fstream>
#include <iostream>
void read_off_file(char* input_c, char* output_c)
{
	std::string input = input_c;
	std::string output = output_c;
	float vertex[10000][3];
	int surface[10000][3];
	/*函数说明：读取off文件
	* */
	char k;
	int vertex_num;
	int surface_num;
	int other_num;
	int i, j;
	int s;
	std::ifstream fin;
	std::ofstream fout;
	fin.open(input);
	while (fin.fail())
	{
		std::cout << "Fail to open the file!" << std::endl;
		exit(1);
	}
	fout.open(output);
	while (fout.fail())
	{
		std::cout << "Fail to open the fail!" << std::endl;
		exit(1);
	}
	do
	{
		std::cout << fin.get();
	} while (fin.get() != '\n');
	fin >> vertex_num >> surface_num >> other_num;
	std::cout << vertex_num;
	for (i = 0; i < vertex_num; i++)
	{
		for (j = 0; j < 3; j++)
		{
			fin >> vertex[i][j];
		}
	}
	for (i = 0; i < surface_num; i++)
	{
		fin >> s;
		std::cout << s << std::endl;
		for (j = 0; j < 3; j++)
		{
			fin >> surface[i][j];
		}
	}

	for (i = 0; i < vertex_num; i++)
	{
		fout.put('v');
		fout.put(' ');
		for (j = 0; j < 3; j++)
		{
			fout << vertex[i][j];
			fout.put(' ');
		}
		fout.put('\n');

	}
	fout.put('\n'); //注意控制换行

	for (i = 0; i < surface_num; i++)
	{
		fout.put('f');
		fout.put(' ');
		for (j = 0; j < 3; j++)
		{
			fout << (surface[i][j] + 1);
			fout.put(' ');
		}
		fout.put('\n');
	}
	fin.close();
	fout.close();
	std::cout << "end" << std::endl;
}
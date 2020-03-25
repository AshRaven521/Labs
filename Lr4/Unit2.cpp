//---------------------------------------------------------------------------


#pragma hdrstop

#include "Unit2.h"
#include <cstring>

#pragma once


int stack::prior(char x)
	{
		if ((x == '*') || (x == '/')) return 2;
		if ((x == '+') || (x == '-')) return 1;
		if ((x == '(') || (x == ')')) return 0;
	}

bool stack::empty()
{
	return top == 0;
}

char stack::get_top_element()
{
	return body[top];
}

int stack::top_prior()
{
	return prior(body[top]);
}

void stack::push(char x)
{
	top++;
	body[top] = x;
}

char stack::pop()
{
	top--;
	return body[top + 1];
}




void stackint::push(double x)
{
	top++;
	sum.push_back(x);
}

void stackint::pop()
{
	top--;
	sum.erase(sum.end() - 1);
}

double stackint::get_top_element()
{
	return sum[top - 1];
}

double stackint::Calc(const std::string& pnote)
{
	stackint final;

	//����� ������ �� �������,�������� ������ � ����� �������
	char temparr[20];
	strcpy(temparr,pnote.c_str());
	char *pch = strtok(temparr," ");
	while(pch!=NULL)
	{
		if(*pch=='+')
		{
			double oper1 = final.get_top_element();
			final.pop();
			double oper2 = final.get_top_element();
			final.pop();
			final.push(oper2 + oper1);
		}
		else
		{
			if(*pch=='-')
			{
				double oper1 = final.get_top_element();
				final.pop();
				double oper2 = final.get_top_element();
				final.pop();
				final.push(oper2 - oper1);
			}
			else
			{
				if(*pch=='*')
				{
					double oper1 = final.get_top_element();
					final.pop();
					double oper2 = final.get_top_element();
					final.pop();
					final.push(oper2 * oper1);
				}
				else
				{
					if(*pch=='/')
					{
						double oper1 = final.get_top_element();
						final.pop();
						double oper2 = final.get_top_element();
						final.pop();
						final.push(oper2 / oper1 * 1.0);
					}
					else
					{
						final.push(std::atof(pch));
					}
				}
			}
		}

		pch=strtok(NULL," ");
	}

	double cd=final.get_top_element();
	return cd;
}

std::string stackint::OPZ(const char(&note)[100])
{
	int i = 0;
	stack s;
	std::string pnote;
	if (note[0] == '-')
	{
		pnote += note[0];
		i++;
	}

	for (; i < strlen(note); i++)
	{
		if (note[i] == '(') s.push(note[i]);
		else if ((note[i] == '+') || (note[i] == '-') || (note[i] == '/') || (note[i] == '*'))
		{
			while ((!s.empty()) && (s.top_prior() >= s.prior(note[i])))
			{
				pnote += s.pop();
				pnote+= " ";
			}
			s.push(note[i]);
		}
		else if (note[i] == ')')
		{
			while ((!s.empty()) && (s.get_top_element() != '('))
			{
				pnote += s.pop();
				pnote += " ";
			}
			s.pop();
		}
		else
		{
			std::string temp = "";
			while (i < strlen(note) && note[i] != '+' && note[i] != '-' && note[i] != '/' && note[i] != '*' && note[i] != '(' && note[i] != ')')
			{
				temp += note[i];
				i++;
			}
			pnote += temp += " ";
			i--;
		}
	}
	while (!s.empty())
	{
		pnote += s.pop();
	}
	return pnote;

}


//---------------------------------------------------------------------------

#pragma package(smart_init)

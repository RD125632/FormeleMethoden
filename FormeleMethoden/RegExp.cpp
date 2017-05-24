#include "RegExp.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>

#include "Automata.h"

RegExp::RegExp()
{
	regOperator = ONE;
	terminals = "";
	left = nullptr;
	right = nullptr;
}

RegExp::RegExp(string p)
{
	regOperator = ONE;
	terminals = p;
	left = nullptr;
	right = nullptr;
}

RegExp::~RegExp()
{
	if (left)
		delete left;
	if(right)
		delete right;
}

RegExp* RegExp::plus()
{
	RegExp* expression = new RegExp();
	expression->regOperator = PLUS;
	expression->left = this;
	return expression;
}

RegExp* RegExp::star()
{
	RegExp* expression = new RegExp();
	expression->regOperator = STAR;
	expression->left = this;
	return expression;
}

RegExp* RegExp::or(RegExp *e2)
{
	RegExp* expression = new RegExp();
	expression->regOperator = OR;
	expression->left = this;
	expression->right = e2;
	return expression;
}

RegExp* RegExp::dot(RegExp *e2)
{
	RegExp* expression = new RegExp();
	expression->regOperator = DOT;
	expression->left = this;
	expression->right = e2;
	return expression;
}

set<string> RegExp::getLanguage(int maxSteps)
{
	set<string> languageLeft, languageRight, emptyLanguage, languageResult;

	if (maxSteps < 1) return emptyLanguage;

	switch (regOperator) {
	case ONE:
	{languageResult.insert(terminals); }

	case OR:
		languageLeft = left == nullptr ? emptyLanguage : left->getLanguage(maxSteps - 1);
		languageRight = right == nullptr ? emptyLanguage : right->getLanguage(maxSteps - 1);
		languageResult.insert(languageLeft.cbegin(), languageLeft.cend());
		languageResult.insert(languageRight.cbegin(), languageRight.cend());
		break;


	case DOT:
		languageLeft = left == nullptr ? emptyLanguage : left->getLanguage(maxSteps - 1);
		languageRight = right == nullptr ? emptyLanguage : right->getLanguage(maxSteps - 1);
		for (string s1 : languageLeft)
			for (string s2 : languageRight)
			{
				languageResult.insert(s1 + s2);
			}
		break;

		// STAR(*) en PLUS(+) kunnen we bijna op dezelfde manier uitwerken:
	case STAR:
	case PLUS:
		languageLeft = left == nullptr ? emptyLanguage : left->getLanguage(maxSteps - 1);
		languageResult.insert(languageLeft.cbegin(), languageLeft.cend());
		for (int i = 1; i < maxSteps; i++)
		{
			set<string> languageTemp;
			languageTemp.insert(languageLeft.cbegin(), languageLeft.cend());
			for (string s1 : languageLeft)
			{
				for (string s2 : languageTemp)
				{
					languageResult.insert(s1 + s2);
				}
			}
		}
		if (regOperator  == STAR)
		{
			languageResult.insert("");
		}
		break;


	default:
		cout << "getLanguage is nog niet gedefinieerd voor de operator: " << regOperator << endl;
		break;
	}


	return languageResult;
}
/*
Automata<string> RegExp::ToNDFA()
{



}*/
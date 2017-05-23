#include "RegExp.h"

RegExp::RegExp()
{
	RegOperator = ONE;
	terminals = "";
	left = nullptr;
	right = nullptr;
}

RegExp::RegExp(string p)
{
	RegOperator = ONE;
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
	expression->RegOperator = PLUS;
	expression->left = this;
	return expression;
}

RegExp* RegExp::star()
{
	RegExp* expression = new RegExp();
	expression->RegOperator = STAR;
	expression->left = this;
	return expression;
}

RegExp* RegExp:: or(RegExp *e2)
{
	RegExp* expression = new RegExp();
	expression->RegOperator = OR;
	expression->left = this;
	expression->right = e2;
	return expression;
}

RegExp* RegExp::dot(RegExp *e2)
{
	RegExp* expression = new RegExp();
	expression->RegOperator = DOT;
	expression->left = this;
	expression->right = e2;
	return expression;
}

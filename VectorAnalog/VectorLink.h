#pragma once

template <class T>
struct VectorLink
{
	T data;
	VectorLink* next = nullptr;
};
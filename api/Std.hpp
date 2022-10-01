#pragma once

#ifndef _STD_INC_H
#define _STD_INC_H

#include <iostream>
#include <vector>
#define _SLC_API __declspec(dllexport)

#ifdef _DEBUG
#define DEBUG(x) x
#else
#define DEBUG(x)
#endif

#endif
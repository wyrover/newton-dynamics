/* Copyright (c) <2009> <Newton Game Dynamics>
*
* This software is provided 'as-is', without any express or implied
* warranty. In no event will the authors be held liable for any damages
* arising from the use of this software.
*
* Permission is granted to anyone to use this software for any purpose,
* including commercial applications, and to alter it and redistribute it
* freely
*/

#ifndef _DCIL_INSTRUC_BRANCH_H_
#define _DCIL_INSTRUC_BRANCH_H_


#include "dCIL.h"
#include "dCILInstr.h"


class dCILInstrLabel: public dCILSingleArgInstr
{
	public:
	dCILInstrLabel(dCIL& program, const dString& label);
	void Serialize(char* const textOut) const;
};

class dCILInstrGoto: public dCILSingleArgInstr
{
	public:
	dCILInstrGoto(dCIL& program, const dString& label);
	void Serialize(char* const textOut) const;

	void SetTarget (dCILInstrLabel* const target0);

	dList<dCILInstr*>::dListNode* m_tagetNode;
};

class dCILInstrIF: public dCILThreeArgInstr
{
	public:
	dCILInstrIF (dCIL& program, const dString& name, const dArgType& type, const dString& target0, const dString& target1);
	void Serialize(char* const textOut) const;

	void SetTargets (dCILInstrLabel* const target0, dCILInstrLabel* const target1) ;
	dList<dCILInstr*>::dListNode* m_tagetNode0;
	dList<dCILInstr*>::dListNode* m_tagetNode1;
};


class dCILInstrReturn: public dCILSingleArgInstr
{
	public:
	dCILInstrReturn(dCIL& program, const dString& name, const dArgType& type);
	void Serialize(char* const textOut) const;
};

class dCILInstrCall: public dCILTwoArgInstr
{
	public:
	dCILInstrCall(dCIL& program, const dString& returnValue, const dArgType& type, const dString& target, dList<dArg>& parameters);
//	dCILInstrCall(dCIL& program, const dString& name, const dArgType& type, dList<dArg>& parameters);
	void Serialize(char* const textOut) const;

	dList<dArg> m_parameters;
};


#endif
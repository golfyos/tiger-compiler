#pragma once
namespace Tiger {
	class BasedType
	{
	public:
		BasedType() = default;
		virtual ~BasedType();
	};

	class ArrayType:public BasedType
	{
	public:
		ArrayType() = default;
		virtual ~ArrayType();
	};

	class BuiltInType:public BasedType
	{
	public:
		BuiltInType() = default;
		virtual ~BuiltInType();
	};

	class IntType: public BuiltInType
	{
	public:
		IntType() = default;
		virtual ~IntType();
	};

	class FloatType: public BuiltInType
 	{
	public:
		FloatType() = default;
		virtual ~FloatType();
	};
}


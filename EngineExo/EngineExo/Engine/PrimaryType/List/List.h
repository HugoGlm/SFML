#pragma once
#include "IList.h"
#include "../ValueType/ValueType.h"
#include "../../Utils/DebugMacro.h"
#include "../../Utils/Template/Pointer.h"
#include "../../Utils/CoreDefine.h"
#include "../../PrimaryType/Integer/Integer.h"
#include <vector>

namespace Engine::PrimaryType
{
	template<typename InElementType, typename InSizeType = size_t>
	class List : public ValueType, public IList
	{
#pragma region f/p
	private:
		typedef typename std::vector<InElementType>::iterator Iterator;
		typedef typename std::vector<InElementType>::const_iterator ConstIterator;
		typedef std::vector<InElementType> ElementType;
		ElementType data = ElementType();
#pragma endregion
#pragma region constructor
	public:
		List() = default;
		List(List&&) = default;
		List(const List&) = default;
		List(const std::initializer_list<InElementType>& _tab)
		{
			for (const InElementType& _item : _tab)
				Add(_item);
		}
#pragma endregion
#pragma region methods
	public:
		void Add(InElementType _item)
		{
			data.push_back(_item);
		}
		void Remove(InElementType _item)
		{
			const size_t _index = Find(_item);
			if (_index == INDEX_NONE)
				return;
			RemoveAt(_index);
		}
		void RemoveAt(size_t _index)
		{
			data.erase(data.begin() + _index);
		}
		size_t Find(InElementType _item)
		{
			const size_t _size = data.size();
			for (size_t i = 0; i < _size; ++i)
			{
				if (data[i] == _item)
					return i;
			}
			return INDEX_NONE;
		}
		void Contains(InElementType _item)
		{
			return Find(_item) != INDEX_NONE;
		}
		Iterator begin() { return data.begin(); }
		ConstIterator begin() const { return data.begin(); }
		Iterator end() { return data.end(); }
		ConstIterator end() const { return data.end(); }
		size_t Count() const override { return data.size(); }
#pragma endregion
#pragma region operator
	public:
		InElementType& operator[](size_t _index)
		{
			return data[_index];
		}
		InElementType& operator[](size_t _index) const
		{
			return data[_index];
		}
#pragma endregion

	};
}
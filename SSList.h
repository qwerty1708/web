#pragma once
namespace SS {
	template <class T>
	class List
	{
		T* head;
		T* last;
		int count;
	public:
		class Element
		{
			T data;
			T* next;
			T* prev;
		public:
			Element();
			~Element();

		private:

		};

		Element::Element()
		{
		}

		Element::~Element()
		{
		}

		List() {
		}
		~List() {

		}
	};
}


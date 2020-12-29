typedef int Item;

class List
{
	static const int Max = 10;
	Item items[Max];
	int top = 0;
public:
	List();
	bool push(const Item& item);
	void visit(void (*pf)(Item&));
	bool isempty() const;
	bool isfull() const;
	
};

void cShow(Item& item);
void cChange(Item& item);
#include "node.h"

class CharNode : public Node
{
	char c;

public:

	CharNode(char ch);

	void get_data(void *p);
};

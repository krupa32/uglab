class Sorter
{
public:
	virtual void sort(char **arr, int size) = 0;
	static Sorter * create(void);
};



class Array
{
  private:
    const int dim;
    int *size;
    struct Address
    {
        int level;
        void *next;
    };
    Address *top;

  public:
    Array(int dim, int *array_size) : dim(dim)
    {
        size = new int[dim];
        for (int i = 0; i < dim; i++)
            size[i] = array_size[i];
        top = new Address;
        top->level = 0;
        init_address(top);
    }
};

void init_address(Address *current)
{
    if (!current)
        return;
    if (current->level == dim - 1)
    {
        current->next = new int[size[current->level]];
        return;
    }
    current->next = new Address[size[current->level]];
    for (int i = 0; i != size[current->level]; i++)
    {
        static_cast<Address *>(current->next) + i)->level = current->level + 1;
        init_address(static_cast<Address *>(current->next) + i);
    }
}

void del_address(Address *current)
{
    if (!current)
        return;
    for (int i = 0; current->level < dim - 1 && i < size[current->level]; i++)
        del_address(static_cast<Address *>(current->next) + i);
    if (current->level == dim - 1)
        delete[] static_cast<int *>(current->next);
    delete[] static_cast<Address *>(current->next);
}

template <typename T>
int easyfind(T& type, int i)
{

    typename T::iterator it;

    for (it = type.begin(); it != type.end(); it++)
    {
        if (*it == i)
            return 0;
    }
    return 1;
}

/*
Rewrite advance() so that it will “go backward” when you give it a negative argument.
*/

template<typename Iter> // requires bidirection p++ & p--
void advance(Iter& p, int n)
{
    while (0 < n) { ++p; --n; }
    while (n < 0) { --p; ++n; }
}

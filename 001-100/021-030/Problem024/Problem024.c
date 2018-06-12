
enum TEST { ZERO, ONE, TWO };
int main()
{
	int t = 3;
	switch( t )
	{
	case ZERO:
	case ONE:
	case TWO:
	default:
		break;
	}
}
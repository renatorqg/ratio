class Ratio
{
	friend Ratio operator*(const Ratio&, const Ratio&);
	
	public:
		Ratio(int n=0, int d=1): num(n), den(d) { reduce(); }
		Ratio(const Ratio&);
		Ratio& operator=(const Ratio&);
		void print() const { cout << num << '/' << den << endl; }
		// outras declaraÃ§Ãµes aqui
	private:
		int num, den;
		void reduce();
		// outras declaraÃ§Ãµes aqui
};

int gcd(int, int);
int lcm(int, int);

Ratio operator*(const Ratio& x, const Ratio& y)
{
	Ratio z(x.num * y.num, x.den * y.den);
	return z;
}

Ratio& Ratio::operator=(const Ratio& r)
{
	num = r.num;
	den = r.den;
	return *this;
}

void Ratio::reduce()
{
	// impÃµe invariante (den > 0)
	if (num == 0 || den ==0)
	{
		num = 0;
		den = 1;
		return;
	}
	if (den < 0)
	{
		den *= -1;
		num *= -1;
	}
	// impÃµe invariante (dcd(num,den) == 1);
	if (den == 1) return; // ele ja estÃ¡ reduzido
	int sgn = (num<0?-1:1); // nenhum negativo para gcd()
	int g = gcd(sgn*num,den);
	num /= g;
	den /= g;
}

int gcd(int m, int n)
{
        // retorna o mÃ¡ximo divisor comum de n e m:
        if (m < n) swap(m,n);
        while (n>0)
        {
                int r=m%n;
                m = n;
                n = r;
        }
        return m;
}

int lcm(int m, int n){
    return (m*n)/gcd(m,n);
}

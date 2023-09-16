#include<iostream>

class Temper {
public:
	virtual double GetGrad() = 0;
	virtual ~Temper(){}
};

class CelTemper :public Temper {
private:
	double _grad;
public:
	CelTemper(double gr):_grad(gr){}
	~CelTemper(){}
	virtual double GetGrad() override{
		return _grad;
	}

};

class FarTemper :public Temper {
private:
	double _gradF;
public:
	FarTemper(double gr) :_gradF(gr) {}
	~FarTemper(){}
	virtual double GetGrad()override {
		return _gradF;
	}

};

class Adapter :public Temper {
private:
	FarTemper* _temF;
	double _ad;
public:
	Adapter(FarTemper*far):_temF(far),_ad(0){}
	~Adapter(){}
	virtual double GetGrad()override {
		_ad = _temF->GetGrad() * 1.8 + 32;
		return _ad;
	}
};

int main() {
	setlocale(LC_ALL, "Russian");

	CelTemper* C = new CelTemper(30);
	FarTemper* F = new FarTemper(5);
	Temper* FA = new Adapter(F);
	std::cout << "Температура " << C->GetGrad() << " цельсий\n";
	std::cout << "Темпераура " << F->GetGrad() << " фаренегейт равна " << FA->GetGrad() << " в цельсиях\n";


	return 0;
}
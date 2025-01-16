#include <iostream>
#include <string>

using namespace std;
enum Type { CITY, NIGHT, EXTRA_URBAN};
class BusLine 
{

private:
	const int lineId;
	string route;
	Type type;
	bool isElectric;
	int* kmPerDay;
	int noDays;
	static float AVERAGE_PRICE_PER_KM;
public:
	BusLine(): lineId(0), route("Mercedes"), type(CITY), isElectric(false), kmPerDay(nullptr), noDays(0)
	{
		
	}
	BusLine(int lineId, string route, Type type) : lineId(lineId), isElectric(false), kmPerDay(nullptr), noDays(0)
	{
		this->route = "Mercedes";
		this->type = type;
	}
	BusLine(int lineId, string route, int* kmPerDay, int noDays, Type type) : lineId(lineId)
	{
		this->isElectric = isElectric;
		this->route = route;
		this->type = type;
		if (this->kmPerDay != nullptr)
		{
			delete[] this->kmPerDay;
		}
		this->kmPerDay = new int[noDays];
		for (int i = 0; i < noDays; i++)
		{
			this->kmPerDay[i] = kmPerDay[i];
		}
		this->noDays = noDays;
	}
	BusLine(const BusLine& b) : lineId(b.lineId)
	{
		this->route = b.route;
		this->type = b.type;
		if (this->kmPerDay != nullptr)
		{
			delete[] this->kmPerDay;
		}
		this->kmPerDay = new int[b.noDays];
		for (int i = 0; i < b.noDays; i++)
		{
			this->kmPerDay[i] = b.kmPerDay[i];
		}
		this->noDays = b.noDays;
	}
	int getNoDays()
	{
		return this->noDays;
	}
	
	string getBrand()
	{
		return this->route;
	}
	int getTotalKilometers()
	{
		int total = 0;
		for (int i = 0; i < this->noDays; i++)
		{
			total += this->kmPerDay[i];
		}
		return total;
	}
	const int getId()
	{
		return this->lineId;
	}

	operator float()
	{
		float total = 0;
		for (int i = 0; i < this->noDays; i++)
		{
			total += this->kmPerDay[i];
		}
		return total;
	}

	
	
	BusLine& operator= (BusLine& b)
	{
		this->route = b.route;
		this->type = b.type;
		if (this->kmPerDay != nullptr)
		{
			delete[] this->kmPerDay;
		}
		this->kmPerDay = new int[b.noDays];
		for (int i = 0; i < b.noDays; i++)
		{
			this->kmPerDay[i] = b.kmPerDay[i];
		}
		this->noDays = b.noDays;
		return *this;
	}
	/*BusLine& operator*(float val)
	{
		for (int i = 0; i < this->noDays; i++)
		{
			this->kmPerDay[i] *= val;
		}
		return *this;
	}*/
	/*float getDayCost(float val)
	{

	}*/
	bool operator>=(const BusLine& b)
	{
		return this->kmPerDay >= b.kmPerDay;
	}

	~BusLine()
	{
		
		if (this->kmPerDay != nullptr)
		{
			cout << "call the destructor " << endl;
			delete[] this->kmPerDay;
		}
	}

	friend ostream& operator<<(ostream& out, BusLine& b);
};
 float AVERAGE_PRICE_PER_KM = 5.5;

 ostream& operator<<(ostream& out, BusLine& b)
 {
	 out << "Introduce the line id: " << b.lineId << endl;
	 out << "Introduce the route : " << b.route << endl;
	 out << " Introduce the route type " << b.type << endl;
	 out << "The nr of days: " << b.noDays << endl;
	 if (b.isElectric == true)
	 {
		 out << "Is electric";
	 }
	 else
	 {
		 out << "Not electric" << endl;
	 }
	  for (int i = 0; i < b.noDays; i++)
	 { 
		  out << "KM per Day: " << i + 1 << b.kmPerDay[i] << endl;
	 }
	  return out;
 }

void main()
{
	BusLine bus1(301, "Piata Romana - Piata Unirii", CITY);
	cout << bus1.getBrand(); // prints Mercedes
	int kilometers[]{ 10,15,15,30,10,10,10 };
	cout << endl;
	BusLine bus2(3, "Corbeanca- Piata Romana", kilometers, 7, NIGHT);
	cout << "\n" << bus2.getTotalKilometers(); // prints 100

	cout << endl;

	BusLine bus3 = bus2;
	cout << "\n" << bus3.getId();  // prints 3
	//bus3.setElectric();

	//bus3.addDay(50);
	cout << "\n" << bus3.getNoDays();  // prints 7

	bus1 = bus3;
	//cout << "\n" << bus1.getDayCost(3);

	//BusLine::AVERAGE_PRICE_PER_KM = 5.4;
	cout << bus1;

	float totalKM = (float)bus1;
	cout << "\n" << totalKM;

	//BusLine bus4 = bus1 * 10;
	//cout << bus4;


	if (bus1 >= 1000)
		cout << "\n Bus Line 1 has at least 1000 recorded km";
	else
		cout << "\n Bus Line 1 hasn't 1000 recorded km";
	
	
}
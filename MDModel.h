#pragma once
#include <vector>


class MDModel
{


	using Vector = std::vector<double>;
	// using Matrix = std::vector<Vector>;

public:

	// Constructor with parameters
	MDModel(const Vector& initial_asset_vector, const double& correlation_rate);
	// Methods that are generated by the compiler if not user-defined
	MDModel(const MDModel& model); // copy operator
	MDModel& operator=(const MDModel& model); // copy assignment operator
	virtual ~MDModel() = default; // virtuelle pure
	// pure virtual methods so MDModel class is an abstract class
	virtual Vector drift_vector_term(const double& time, const Vector& asset_vector) const = 0;
	virtual Vector diffusion_vector_term(const double& time, const Vector& asset_vector) const = 0;
	virtual MDModel* clone() const = 0;

	inline Vector init_value() const
	{
		return _initial_asset_vector;
	}

	inline double correlation() const
	{
		return _correlation_rate;
	}

	virtual double sigma_vol() const = 0;
	virtual double kappa() const = 0;
	virtual double theta() const = 0;
	virtual double interest_rate() const = 0;



protected:
	Vector _initial_asset_vector; // (S_0, V_0)
	double _correlation_rate; // Correlation rate rho

};



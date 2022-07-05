#include "error_state_kalman_filter.h"

// Initialize Static member variables
Mat33 ESKF::I33 = Mat33::Identity();
Mat44 ESKF::I44 = Mat44::Identity();
Mat33 ESKF::O33 = Mat33::Zero();
Mat44 ESKF::O44 = Mat44::Zero();
Mat34 ESKF::O34 = Mat34::Zero();
Mat43 ESKF::O43 = Mat43::Zero();    

ESKF::ESKF()
: measurement_noise_(), process_noise_(), X_nom_(), dX_()
{
    P_ = CovarianceMat::Identity()*0.005;

    std::cout << "P_:\n";
    std::cout << P_ << std::endl;

    std::cout << "Q_:\n";
    std::cout << process_noise_.Q << std::endl;

    std::cout << "R_:\n";
    std::cout << measurement_noise_.R << std::endl;

    std::cout << "Error State Kalman Filter - constructed\n";
};

ESKF::~ESKF(){
    std::cout << "Error State Kalman Filter - destructed\n";
};

void ESKF::predict(double ax, double ay, double az, double wx, double wy, double wz, double t_now){
    // Do implementation
    std::cout << "Predict...\n";
    double dt = t_now - t_prev_;
    t_prev_ = t_now;

    // Do prediction    
    // 0. measurement
    Vec3 am(ax,ay,az);
    Vec3 wm(wx,wy,wz);

    // 1. nominal state propagation
    NominalState X_nom_prev = X_nom_;
    ErrorState dX_prev = dX_;
    // X_nom_ = predict_nominal(X_nom_prev, am, wm, dt);

    // 2. error-state propagation
    // dX_ = predict_error(X_nom_prev, dX_, )

    // 3. Error Covariance propagation
    // F0 = errorStateF(X_nom_prev, dX_prev,am,wm);
    // eF0dt = expm(F0 * dt);
    // P_ = eF0dt * P_ * eF0dt.transpose() + Fi * Q_*Fi.transpose();
};

void ESKF::update(){
    // Do implementation
    std::cout << "Update...\n";


};
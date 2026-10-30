#include "TiltSensor.hpp"

constexpr double RAD_TO_DEG = 180.0 / 3.14159265358979323846;

TiltSensor::TiltSensor(double mu) : mu_(mu) {}

EulerAngles TiltSensor::calculateAerospaceAngles(const AccelReading& g) const {
    // Pitch (Equação 37): sempre estável usando a raiz quadrada no denominador
    double denom_pitch = std::sqrt(g.y * g.y + g.z * g.z);
    double pitch_rad = std::atan2(-g.x, denom_pitch);

    // Roll (Equação 38): usa o fator mu e o sinal de Gpz para evitar instabilidade na vertical
    double sign_gz = (g.z >= 0.0) ? 1.0 : -1.0;
    double denom_roll = sign_gz * std::sqrt(g.z * g.z + mu_ * (g.x * g.x));
    double roll_rad = std::atan2(g.y, denom_roll);

    return { roll_rad * RAD_TO_DEG, pitch_rad * RAD_TO_DEG };
}

double TiltSensor::calculateTiltAngle(const AccelReading& g) const {
    // Módulo do vetor e cálculo do ângulo de tilt (Equação 55 do PDF)[cite: 23]
    double magnitude = std::sqrt(g.x * g.x + g.y * g.y + g.z * g.z);
    if (magnitude == 0.0) return 0.0;
    
    double cos_rho = g.z / magnitude;
    // Proteção contra valores inválidos no acos devido a ruído
    if (cos_rho > 1.0) cos_rho = 1.0;
    if (cos_rho < -1.0) cos_rho = -1.0;

    return std::acos(cos_rho) * RAD_TO_DEG;
}
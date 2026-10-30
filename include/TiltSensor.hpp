#pragma once
#include <cmath>

// Estrutura para os dados do acelerômetro (Gpx, Gpy, Gpz)
struct AccelReading {
    double x;
    double y;
    double z;
};

// Estrutura para os ângulos de saída
struct EulerAngles {
    double roll_deg;
    double pitch_deg;
};

class TiltSensor {
private:
    double mu_; // Fator de estabilidade para evitar divisão por zero (conforme PDF AN3461)

public:
    // Construtor
    explicit TiltSensor(double mu = 0.01);

    // Método para calcular Roll e Pitch usando a Sequência Aeroespacial R_xyz (Equações 37 e 38 do PDF)
    EulerAngles calculateAerospaceAngles(const AccelReading& g) const;

    // Método para calcular o ângulo de Tilt (inclinação em relação à vertical - Equação 55 do PDF)
    double calculateTiltAngle(const AccelReading& g) const;
};
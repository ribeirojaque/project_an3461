#include <iostream>
#include "TiltSensor.hpp"

int main() {
    std::cout << "=== Testando o Calculador de Inclinação (Hexagon Prep) ===\n\n";

    // Dados do Worked Example 1 da página 12 do PDF AN3461:
    // Gp = (0.461105, 0.082198, -0.887432)[cite: 16]
    AccelReading leitura_ex1 = { 0.461105, 0.082198, -0.887432 };

    TiltSensor sensor(0.01); // Instanciando o objeto com mu = 0.01
    EulerAngles angulos = sensor.calculateAerospaceAngles(leitura_ex1);
    double tilt = sensor.calculateTiltAngle(leitura_ex1);

    std::cout << "Resultados obtidos via POO:\n";
    std::cout << " -> Pitch: " << angulos.pitch_deg << " deg (Esperado no PDF: -27.3561)\n";
    std::cout << " -> Roll:  " << angulos.roll_deg  << " deg (Esperado no PDF: 174.7081)\n";
    std::cout << " -> Tilt:  " << tilt << " deg\n\n";

    std::cout << "Teste executado com sucesso!\n";
    return 0;
}
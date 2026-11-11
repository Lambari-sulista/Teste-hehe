#include <iostream> 
#include <string> // Corrigido de <string.h> para <string>

template <typename T>
class Celula {
protected:
    T dado;
public:
    // Corrigido: 'Celula' com C maiúsculo para coincidir com a classe
    Celula(T con) : dado(con) {} 

    virtual void exibir() const {
        std::cout << dado << std::endl;
    }
    
    virtual ~Celula() = default; // Boa prática: destrutor virtual para classes base
};

// Invertida a ordem para <typename U, typename T> para corresponder a (Chave/ID, Dado)
template <typename U, typename T>
class CelulaFor : public Celula<T> {
public:
    U chave; // Corrigido o tipo da chave para U

    // U é o tipo do ID/chave, T é o tipo do conteúdo repassado à classe base Celula<T>
    CelulaFor(U id, T con) : Celula<T>(con), chave(id) {}

    void exibir() const override {
        std::cout << chave << " : " << this->dado << std::endl;
    }
};

int main() {
    // c1: U = double (3.14), T = int (2)
    auto c1 = CelulaFor(3.14, 2);

    // c2: U = std::string ("bob"), T = int (10)
    auto c2 = CelulaFor(std::string{"bob"}, 10);

    c1.exibir(); // Saída: 3.14 : 2
    c2.exibir(); // Saída: bob : 10
    std::cout << "bom dia" << std::endl;
    return 0;
}
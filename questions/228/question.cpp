template <typename ...Ts>
struct X {
  X(Ts ...args) : Var(0, args...) {}
  int Var;
};

int main() {
  X<> x;
}
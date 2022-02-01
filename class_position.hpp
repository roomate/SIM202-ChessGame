class Position
{public:
    int joueur;
    Position(int J) : joueur(J) {}
    virtual double valeur_position() const =0;
    Position* fille(joueur%2+1);
    Position* soeur(joueur);
    virtual ~delete(){};
    virtual position& position_possible() = 0;
    virtual void print_position(ostram& out) const = 0;
};

class Position_morpion : public Position
{
public:
    grille G();
    int possession(int i, int j) const {return G.T[i*G.m+j]}
    ~delete()
    {
        if (G != nullptr) delete[] G;
    }
    Position_morpion& position_possible();
};

class grille{
    int* T;
    grille(const grille& g);
    grille();
    ostream& print_grille(ostream& out);
    bool a_gagne(int joueur);
    bool grille_pleine();
};
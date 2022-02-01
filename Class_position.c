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

    Position_morpion& position_possible()
    {
        Position_morpion** Tableau_soeurs = new Position_morpion*[9];
        Position_morpion* Pfille = Tableau_soeurs[0];
        this->fille = Pfille;
        int k = 0;
        for (int i = 0; i<G.m*G.n; i++)
        {
            if (this->G.T[i] == 0)
            {
                Tableau_soeurs[k]->joueur = this->joueur%2+1
                Tableau_soeurs[k]->G = this->G;
                Tableau_soeurs[k]->G.T[i] = this->joueur;
                k+=1;
                Tableau_soeurs[k-1]->soeur = Tableau_soeur[k];
            }
        }
    return Pfille;
    }
};

class Grille
{
public:
    int* T;
    Grille(int m = 3, int n = 3,val = 0)
    {
        T = new int[m*n]
        for (int i = 0; i<m*n;i++)
            T[i] = val;
    }
    ostream& affiche_grille(ostream& out)
    {
        for (int j = 0; j<3; j++)
            for (int i = 0; i<3; i++)
        {
            if (T[i+3*j] ==0)
                return out<<".";
        }
            if (T[i+3*j] ==1)
                return out<<"X";
            if (T[i+3*j] ==2)
            {
                return out<<"O";
            }
    }
    return out;
};

#include <iostream>
#include <conio.h>

using namespace std;

struct paises{
   int codigo_pais;
   string nome;
   int status;
};

struct indice_pais {
    int codigo_pais;
    int ender;
};

struct cidade{
    int codigo_cidade;
    string nome;
    char uf[2];
    int codigo_pais;
    int status;
};

struct indice_cid {
    int codigo_cidade;
    int ender;
};

struct guias{
    int codigo_guia;
    string nome;
    string endereco;
    char telefone[11];
    int codigo_cidade;
    int status;
};

struct indice_guia {
    int codigo_guia;
    int ender;

};

struct cliente{
    int codigo_cliente;
    string nome;
    string endereco;
    int codigo_cidade;
    int status;
};

struct indice_cliente {
    int codigo_cliente;
    int ender;
};

struct pacote{
    int codigo_pacote;
    string descricao;
    int codigo_guia;
    float valor_pessoa;
    int total_partic;
    int quant_maxPartic;
    int status;
};

struct indice_pacote {
    int codigo_pacote;
    int codigo_guia;
    int ender;
};

struct venda{
    int codigo_venda;
    int codigo_cliente;
    int codigo_pacote;
    int quant_pessoa;
    float valor_total;
    int status;
};

struct indice_venda {
    int codigo_venda;
    int codigo_cliente;
    int ender;
};

void leitura_pais(paises pais[], int &cont){
    int i=0;
    for (int saida = 1; i < 10 && saida !=0 ; i++) {
        cout <<"\n\nCodigo Pais " <<(i+1) <<": ";
        cin >> pais[i].codigo_pais;
        if(pais[i].codigo_pais > 0){
            cout << "\nNome: ";
            cin >> pais[i].nome;
            pais[i].status=0;
        }
        else saida=0;
    }
    cont = i-1;
}

void lei_ind_pais(indice_pais idx_pais[], int cont){
    for (int i = 0; i < cont; i++) {
        cout << "\n\nCodigo do Indice " << (i+1) << ": ";
        cin >> idx_pais[i].codigo_pais;
        cout << "Endereco Fisico na Area de Dados: ";
        cin >> idx_pais[i].ender;

    }
}

int busca_pais( indice_pais idx_pais[],  paises pais[], int &cont, int cod){
    int i = 0, f = cont;
    int m = (i + f) / 2;
    for (; f >= i && cod != idx_pais[m].codigo_pais; m = (i + f) / 2){
        if (cod > idx_pais[m].codigo_pais)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == idx_pais[m].codigo_pais){
        cout << "\n\nPais encontrado";
        i = pais[i].codigo_pais;
        cout << "\nCodigo do Pais: " << pais[i].codigo_pais;
        cout << "\tNome: " << pais[i].nome;
        return m;
    }
    else
        cout << "\n\n Pais nao Encontrado";
        return -1;
}

void leitura_cid(cidade cid[], indice_pais indx[], paises pais[], int &cont){
    int i=0;
    int posicaoPais;
    int novoPais;
    for (int saida = 1; i < 10 && saida !=0 ; i++) {
        cout <<"\n\nCodigo Cidade " <<(i+1) <<": ";
        cin >> cid[i].codigo_cidade;
        if(cid[i].codigo_cidade > 0){
            cout << "\nNome: ";
            cin >> cid[i].nome;
            cout << "\nCodigo Pais: ";
            cin >> posicaoPais;
           novoPais= busca_pais(indx,pais,cont ,posicaoPais );
            if (novoPais == -1) {
                cout << "\n\nCodigo invalido";
                cin >> posicaoPais;
                novoPais = busca_pais(indx,pais,cont ,posicaoPais );;
            }else{
                cid[i].codigo_pais = pais[novoPais].codigo_pais;
            }
           cout << "\nEstado: ";
            cin >> cid[i].uf;
            cid[i].status=0;
        }
        else saida=0;
    }
    cont = i-1;
}


void lei_ind_cid(indice_cid idx_cid[], int cont){
    for (int i = 0; i < cont; i++) {
        cout << "\n\nCodigo do Indice " << (i+1) << ": ";
        cin >> idx_cid[i].codigo_cidade;
        cout << "Endereco Fisico na Area de Dados: ";
        cin >> idx_cid[i].ender;

    }
}

int busca_cid ( indice_cid idx_cid[], cidade cid[], int &cont, int cod){
    int i = 0, f = cont;
    int m = (i + f) / 2;
    for (; f >= i && cod != idx_cid[m].codigo_cidade; m = (i + f) / 2){
        if (cod > idx_cid[m].codigo_cidade)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == idx_cid[m].codigo_cidade){
        cout << "\n\nCidade encontrado";
        i = cid[i].codigo_cidade;
        cout << "\nCodigo do Cidade: " << cid[i].codigo_cidade;
        cout << "\nNome: " << cid[i].nome;
        cout << "\nCodigo Pais: " << cid[i].codigo_pais;
        cout << "\nEstado: "<< cid[i].uf;
        return m;
    }
    else
        cout << "\n\n Cidade nao Encontrado";
        return -1;
}

void leitura_guia(guias guia[],indice_cid indx[], cidade cid[], int &cont){
    int i=0;
    int posicaoCid;
    int novoCid;
    for (int saida = 1; i < 10 && saida !=0 ; i++) {
        cout <<"\n\nCodigo Guia " <<(i+1) <<": ";
        cin >> guia[i].codigo_guia;
        if(guia[i].codigo_guia > 0){
            cout << "\nNome: ";
            cin >> guia[i].nome;
            cout << "\nCodigo Cidade: ";
            cin >> posicaoCid;
            novoCid= busca_cid(indx,cid,cont ,posicaoCid );
            if (novoCid == -1) {
                cout << "\n\nCodigo invalido";
                cin >> posicaoCid;
                novoCid = busca_cid(indx,cid,cont ,posicaoCid );;
            }else{
                guia[i].codigo_cidade = cid[novoCid].codigo_cidade;
            }
            cout << "\nTelefone: ";
            cin >> guia[i].telefone;
            cout << "\nEndereco: ";
            cin >> guia[i].endereco;
            guia[i].status=0;
        }
        else saida=0;
    }
    cont = i-1;
}

void lei_ind_guia(indice_guia idx_guia[], int cont){
    for (int i = 0; i < cont; i++) {
        cout << "\n\nCodigo do Indice " << (i+1) << ": ";
        cin >> idx_guia[i].codigo_guia;
        cout << "Endereco Fisico na Area de Dados: ";
        cin >> idx_guia[i].ender;

    }
}

int busca_guia ( indice_guia idx_guia[], guias guia[], int &cont, int cod){
    int i = 0, f = cont;
    int m = (i + f) / 2;
    for (; f >= i && cod != idx_guia[m].codigo_guia; m = (i + f) / 2){
        if (cod > idx_guia[m].codigo_guia)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == idx_guia[m].codigo_guia){
        cout << "\n\nGuia encontrado";
        i = guia[i].codigo_guia;
        cout << "\nCodigo da Cidade: " << guia[i].codigo_cidade;
        cout << "\nNome: " << guia[i].nome;
        cout << "\nTelefone: " << guia[i].telefone;
        cout << "\nEndereco: "<< guia[i].endereco;
        return m;
    }
    else
        cout << "\n\n Guia nao Encontrado";
        return -1;
}
//main
void inclusao_guia(indice_guia idx[], guias guia[], int &cont, int cod){
    cont++;
    guia[cont].codigo_guia = cod;
    cout << "\nNome: ";
    cin >> guia[cont].nome;
    cout << "\nCodigo Cidade: ";
    cin >> guia[cont].codigo_cidade;
    cout << "\nTelefone: ";
    cin >> guia[cont].telefone;
    cout << "\nEndereco: ";
    cin >> guia[cont].endereco;

    int i;
    for (i = cont -1; idx[i].codigo_guia > cod ; i--) {
        idx[i+1].codigo_guia = idx[i].codigo_guia;
        idx[i+1].ender = idx[i].ender;
    }
    idx[i+1].codigo_guia = cod;
    idx[i+1].ender = cont;
    cout << "\n\nInclusao realizada com Sucesso";
};

void leitura_cliente(cliente cli[],indice_cid indx[], cidade cid[], int &cont){
    int i=0;
    int posicaoCid;
    int novoCid;
    for (int saida = 1; i < 10 && saida !=0 ; i++) {
        cout <<"\n\nCodigo Cliente " <<(i+1) <<": ";
        cin >> cli[i].codigo_cliente;
        if(cli[i].codigo_cliente > 0){
            cout << "\nNome: ";
            cin >> cli[i].nome;
            cout << "\nCodigo Cidade: ";
            cin >> posicaoCid;
            novoCid= busca_cid(indx,cid,cont ,posicaoCid );
            if (novoCid == -1) {
                cout << "\n\nCodigo invalido";
                cin >> posicaoCid;
                novoCid = busca_cid(indx,cid,cont ,posicaoCid );;
            }else{
                cli[i].codigo_cidade = cid[novoCid].codigo_cidade;
            }
            cout << "\nEndereco: ";
            cin >> cli[i].endereco;
            cli[i].status=0;
        }
        else saida=0;
    }
    cont = i-1;
}
//main
void lei_ind_cli(indice_cliente idx_cli[], int cont){
    for (int i = 0; i < cont; i++) {
        cout << "\n\nCodigo do Indice " << (i+1) << ": ";
        cin >> idx_cli[i].codigo_cliente;
        cout << "Endereco Fisico na Area de Dados: ";
        cin >> idx_cli[i].ender;

    }
}
//main
int busca_cli ( indice_cliente idx_cli[], cliente cli[], int &cont, int cod){
    int i = 0, f = cont;
    int m = (i + f) / 2;
    for (; f >= i && cod != idx_cli[m].codigo_cliente; m = (i + f) / 2){
        if (cod > idx_cli[m].codigo_cliente)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == idx_cli[m].codigo_cliente){
        cout << "\n\nCliente encontrado";
        i = cli[i].codigo_cliente;
        cout << "\nCodigo da Cidade: " << cli[i].codigo_cidade;
        cout << "\nNome: " << cli[i].nome;
        cout << "\nEndereco: "<< cli[i].endereco;
        return m;
    }
    else
        cout << "\n\n Cliente nao Encontrado";
    return -1;
}
//main
void inclusao_cli(indice_cliente idx[], cliente cli[], int &cont, int cod){
    cont++;
    cli[cont].codigo_cliente = cod;
    cout << "\nNome: ";
    cin >> cli[cont].nome;
    cout << "\nCodigo Cidade: ";
    cin >> cli[cont].codigo_cidade;
    cout << "\nEndereco: ";
    cin >> cli[cont].endereco;

    int i;
    for (i = cont -1; idx[i].codigo_cliente > cod ; i--) {
        idx[i+1].codigo_cliente = idx[i].codigo_cliente;
        idx[i+1].ender = idx[i].ender;
    }
    idx[i+1].codigo_cliente = cod;
    idx[i+1].ender = cont;
    cout << "\n\nInclusao realizada com Sucesso";
};

int main() {
    paises pais[10]; indice_pais ind_pais[10];
    cidade cidade[10]; indice_cid ind_cid[10];
    guias guia[10];  indice_guia ind_guia[10];
    cliente pessoa[10];
    pacote pacote[10];
    venda venda[10];
    int cont_pais;
    leitura_pais(pais,cont_pais);
    cout <<"\nLeitura do Indice";
    lei_ind_pais(ind_pais,cont_pais);

    for (int codpesq = 9; codpesq != 0;){
        cout << "\n\nInforme o Codigo do Pais a ser Buscado (0 para Encerrar): ";
        cin >> codpesq;
        if (codpesq != 0)
            busca_pais( ind_pais, pais, cont_pais, codpesq);
    }

    int cont_cid;
    leitura_cid(cidade,ind_pais,pais,cont_cid);
    cout <<"\nLeitura do Indice";
    lei_ind_cid(ind_cid,cont_cid);

    for (int codpesq = 9; codpesq != 0;){
        cout << "\n\nInforme o Codigo do Cidade a ser Buscado (0 para Encerrar): ";
        cin >> codpesq;
        if (codpesq != 0)
            busca_cid( ind_cid, cidade, cont_cid, codpesq);
    }

    int cont_guia;
    leitura_guia(guia,ind_cid,cidade,cont_guia);
    cout <<"\nLeitura do Indice";
    lei_ind_guia(ind_guia,cont_guia);

    for (int codpesq = 9; codpesq != 0;){
        cout << "\n\nInforme o Codigo do Guia a ser Buscado (0 para Encerrar): ";
        cin >> codpesq;
        if (codpesq != 0)
            busca_guia( ind_guia, guia, cont_guia, codpesq);
    }

    for (int codpesq = 9; codpesq != 0;){
        cout << "\n\nInforme o Codigo do Guia a ser Inclu do (0 para Encerrar): ";
        cin >> codpesq;
        if (codpesq != 0)
           busca_guia(ind_guia, guia, cont_guia, codpesq);
    }


    return 0;
}

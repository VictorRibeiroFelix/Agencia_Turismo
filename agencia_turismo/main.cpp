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
    int pacote;
    int status =0;
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
    int venda;
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
    for (int saida = 1; i < 4 && saida !=0 ; i++) {
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
    int i = 0, f = cont-1;
    int m = (i + f) / 2;
    for (; f >= i && cod != idx_pais[m].codigo_pais; m = (i + f) / 2){
        if (cod > idx_pais[m].codigo_pais)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == idx_pais[m].codigo_pais){
        cout << "\n\nPais encontrado";
        i = idx_pais[m].ender;
        cout << "\nCodigo do Pais: " << pais[i].codigo_pais;
        cout << "\tNome: " << pais[i].nome;
        return m;
    }
    else
        cout << "\n\n Pais nao Encontrado";
    return -1;
}

void leitura_cid(cidade cid[], indice_pais indx[], paises pais[], int &cont, int &cont_pais){
    int i=0;
    int posicaoPais;
    int novoPais;
    for (int saida = 1; i < 4 && saida !=0 ; i++) {
        cout <<"\n\nCodigo Cidade " <<(i+1) <<": ";
        cin >> cid[i].codigo_cidade;
        if(cid[i].codigo_cidade > 0){
            cout << "\nNome: ";
            cin >> cid[i].nome;
            cout << "\nCodigo Pais: ";
            cin >> posicaoPais;
            novoPais= busca_pais(indx,pais,cont_pais ,posicaoPais );
            if (novoPais == -1) {
                cout << "\n\nCodigo invalido";
                cout << "\nCodigo Pais: ";
                cin >> posicaoPais;
                novoPais = busca_pais(indx,pais,cont_pais ,posicaoPais );;
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
    int i = 0, f = cont-1;
    int m = (i + f) / 2;
    for (; f >= i && cod != idx_cid[m].codigo_cidade; m = (i + f) / 2){
        if (cod > idx_cid[m].codigo_cidade)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == idx_cid[m].codigo_cidade){
        cout << "\n\nCidade encontrado";
        i = idx_cid[m].ender;
        cout << "\nCodigo do Cidade: " << cid[i].codigo_cidade;
        cout << "\nNome: " << cid[i].nome;
        cout << "\nCodigo Pais: " << cid[i].codigo_pais;
        cout << "\nEstado: "<< cid[i].uf;
        return i;
    }
    else
        cout << "\n\n Cidade nao Encontrado";
    return -1;
}

void leitura_guia(guias guia[],indice_cid indx[], cidade cid[], int &cont, int &cont_cid){
    int i=0;
    int posicaoCid;
    int novoCid;
    for (int saida = 1; i < 4 && saida !=0 ; i++) {
        cout <<"\n\nCodigo Guia " <<(i+1) <<": ";
        cin >> guia[i].codigo_guia;
        if(guia[i].codigo_guia > 0){
            cout << "\nNome: ";
            cin >> guia[i].nome;
            cout << "\nCodigo Cidade: ";
            cin >> posicaoCid;
            novoCid= busca_cid(indx,cid,cont_cid ,posicaoCid );
            if (novoCid == -1) {
                cout << "\n\nCodigo invalido";
                cout << "\nCodigo Cidade: ";
                cin >> posicaoCid;
                novoCid = busca_cid(indx,cid,cont_cid ,posicaoCid );
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
    int i = 0, f = cont-1;
    int m = (i + f) / 2;
    for (; f >= i && cod != idx_guia[m].codigo_guia; m = (i + f) / 2){
        if (cod > idx_guia[m].codigo_guia)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == idx_guia[m].codigo_guia){
        cout << "\n\nGuia encontrado";
        i = idx_guia[m].ender;
         cout << "\nCodigo do Guia: " << guia[i].codigo_guia;
        cout << "\nCodigo da Cidade: " << guia[i].codigo_cidade;
        cout << "\nNome: " << guia[i].nome;
        cout << "\nTelefone: " << guia[i].telefone;
        cout << "\nEndereco: "<< guia[i].endereco;
        return i;
    }
    else
        cout << "\n\n Guia nao Encontrado";
    return -1;
}

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
    for (i = cont - 1; idx[i].codigo_guia > cod ; i--) {
        idx[i+1].codigo_guia = idx[i].codigo_guia;
        idx[i+1].ender = idx[i].ender;
    }
    idx[i+1].codigo_guia = cod;
    idx[i+1].ender = cont;
    cout << "\n\nInclusao realizada com Sucesso";
}

void busca_inclu_guia ( indice_guia idx[], guias guia[], int &cont, int cod){
    int i = 0, f = cont;
    int m = (i + f) / 2;
    for (; f >= i && cod != idx[m].codigo_guia; m = (i + f) / 2){
        if (cod > idx[m].codigo_guia)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == idx[m].codigo_guia){
        cout << "\n\n Guia ja  Cadastrado - nao pode ser cadastrado novamente";
        i = idx[m].ender;
        cout << "\nCodigo do Guia: " << guia[i].codigo_guia;
        cout << "\nNome: " << guia[i].nome;
        cout << "\nEndereco: " << guia[i].endereco;
        cout << "\nCidade: " << guia[i].codigo_cidade;
        cout << "\nTelefone: " << guia[cont].telefone;
    }
    else
        inclusao_guia(idx, guia, cont, cod);
}

void leitura_pacote(pacote paco[],indice_guia indx[], guias guia[], int &cont, int &cont_guia){
    int i=0;
    int posicaoGuia;
    int novoGuia;
    for (int saida = 1; i < 4 && saida !=0 ; i++) {
        cout <<"\n\nCodigo Pacote " <<(i+1) <<": ";
        cin >> paco[i].codigo_pacote;
        if(paco[i].codigo_pacote > 0){
            cout << "\nDescricao: ";
            cin >> paco[i].descricao;
            cout << "\nCodigo Guia: ";
            cin >> posicaoGuia;
            novoGuia= busca_guia(indx,guia,cont_guia ,posicaoGuia );
            if (novoGuia == -1) {
                cout << "\n\nCodigo invalido";
                cout << "\nCodigo Guia: ";
                cin >> posicaoGuia;
                novoGuia = busca_guia(indx,guia,cont_guia ,posicaoGuia );
            }else{
                paco[i].codigo_guia = guia[novoGuia].codigo_guia;
            }
            cout << "\nValor por pessoa: ";
            cin >> paco[i].valor_pessoa;
            cout << "\nTotal de pessoa: ";
            cin >> paco[i].total_partic;
            cout << "\nQuantidade Maxima de pessoa: ";
            cin >> paco[i].quant_maxPartic;

            paco[i].status=0;
        }
        else saida=0;
    }
    cont = i-1;
}

void lei_ind_paco(indice_pacote idx_paco[], int cont){
    for (int i = 0; i < cont; i++) {
        cout << "\n\nCodigo do Indice " << (i+1) << ": ";
        cin >> idx_paco[i].codigo_pacote;
        cout << "Endereco Fisico na Area de Dados: ";
        cin >> idx_paco[i].ender;

    }
}

int busca_paco ( indice_pacote idx_paco[], pacote paco[], int &cont, int cod){
    int i = 0, f = cont-1;
    int m = (i + f) / 2;
    for (; f >= i && cod != idx_paco[m].codigo_pacote; m = (i + f) / 2){
        if (cod > idx_paco[m].codigo_pacote)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == idx_paco[m].codigo_pacote){
        cout << "\n\nPacote encontrado";
        i = idx_paco[m].ender;
         cout << "\nCodigo do Pacote: " << paco[i].codigo_pacote;
        cout << "\nCodigo do Guia: " << paco[i].codigo_guia;
        cout << "\nDescricao: " << paco[i].descricao;
        cout << "\nValor por pessoa: "<< paco[i].valor_pessoa;
        cout << "\nTotal de pessoa: "<< paco[i].total_partic;
        cout << "\nQuantidade Maxima de pessoa: "<< paco[i].quant_maxPartic;

        float valor_total_arrecadado = paco[i].valor_pessoa * paco[i].total_partic;
        cout << "\nValor Total arrecadado pelo Pacote: " << valor_total_arrecadado << endl;

        return i;
    }
    else
        cout << "\n\n Pacote nao Encontrado";
    return -1;
}

void inclusao_paco(indice_pacote idx[], pacote paco[], int &cont, int cod){
    cont++;
    paco[cont].codigo_pacote = cod;
    cout << "\nDescricao: ";
    cin >> paco[cont].descricao;
    cout << "\nCodigo Guia: ";
    cin >> paco[cont].codigo_guia;
    cout << "\nValor por pessoa: ";
    cin >> paco[cont].valor_pessoa;
    cout << "\nTotal de pessoa: ";
    cin >> paco[cont].total_partic;
    cout << "\nQuantidade Maxima de pessoa: ";
    cin >> paco[cont].quant_maxPartic;

    int i;
    for (i = cont -1; idx[i].codigo_pacote > cod ; i--) {
        idx[i+1].codigo_pacote = idx[i].codigo_pacote;
        idx[i+1].ender = idx[i].ender;
    }
    idx[i+1].codigo_pacote = cod;
    idx[i+1].ender = cont;
    cout << "\n\nInclusao realizada com Sucesso";
}

void busca_inclu_paco ( indice_pacote idx[], pacote paco[], int &cont, int cod){
    int i = 0, f = cont;
    int m = (i + f) / 2;
    for (; f >= i && cod != idx[m].codigo_pacote; m = (i + f) / 2){
        if (cod > idx[m].codigo_pacote)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == idx[m].codigo_pacote){
        cout << "\n\n Pacote ja  Cadastrado - nao pode ser cadastrado novamente";
        i = idx[m].ender;
        cout << "\nCodigo do Guia: " << paco[i].codigo_guia;
        cout << "\nDescricao: " << paco[i].descricao;
        cout << "\nValor por pessoa: "<< paco[i].valor_pessoa;
        cout << "\nTotal de pessoa: "<< paco[i].total_partic;
        cout << "\nQuantidade Maxima de pessoa: "<< paco[i].quant_maxPartic;
    }
    else
        inclusao_paco(idx, paco, cont, cod);
    getch();
}

void buscaGuia_exclu(indice_guia idx[], guias guia[], indice_pacote idx_paco[], pacote paco[], int &cont, int cod) {
    int i = 0, f = cont ;
    int m;

    while (i <= f) {
        m = (i + f) / 2;
        if (cod == idx[m].codigo_guia) {
            break;
        } else if (cod > idx[m].codigo_guia) {
            i = m + 1;
        } else {
            f = m - 1;
        }
    }

    if (i > f) {
        cout << "Guia nao encontrada." << endl;
        return;
    }

    int guia_index = idx[m].ender;

    bool tem_pacote = false;
    for (int j = 0; j < cont; j++) {
        if (paco[idx_paco[j].codigo_pacote].codigo_guia == guia[guia_index].codigo_guia) {
            tem_pacote = true;
            break;
        }
    }

    if (tem_pacote) {
        cout << "Nao e possivel excluir o guia. O guia esta vinculada a um pacote." << endl;
        return;
    }

    if (guia[guia_index].status == 0) {
        guia[guia_index].status = 1;
        cout << "\n\nGuia excluida com sucesso." << endl;
    } else {
        cout << "Guia ja esta excluida." << endl;
    }
}

void reorg_guia (struct indice_guia idx[], struct guias guia[], int &cont){
    struct guias novo[cont];
    int j=-1;
    for (int k=0; k < cont; k++){
        int i = idx[k].ender;
        if (guia[i].status == 0){
            j++;
            novo[j] = guia[i];
            idx[j].codigo_guia = novo[j].codigo_guia;
            idx[j].ender = j;
        }
    }
    cont = j+1;
    for (int k = 0; k < cont; k++){
        int i = idx[k].ender;
        guia[k] = novo [i];
    }
}

void exaustiva_guia (struct indice_guia idx[], struct guias guia[], int cont){
    for (int k=0; k < cont; k++){
        int i = idx[k].ender;
        if (guia[i].status == 0){
            cout << "\nEnd Fisico: " << i;
            cout << "\nNome: " << guia[i].nome;
            cout << "\tEndereco: " << guia[i].endereco;
            cout << "\tCidade: " << guia[i].codigo_cidade;
            cout << "\tTelefone: " << guia[i].telefone;
        }
    }
}

void leitura_cliente(cliente cli[],indice_cid indx[], cidade cid[], int &cont, int &cont_cid){
    int i=0;
    int posicaoCid;
    int novoCid;
    for (int saida = 1; i < 4 && saida !=0 ; i++) {
        cout <<"\n\nCodigo Cliente " <<(i+1) <<": ";
        cin >> cli[i].codigo_cliente;
        if(cli[i].codigo_cliente > 0){
            cout << "\nNome: ";
            cin >> cli[i].nome;
            cout << "\nCodigo Cidade: ";
            cin >> posicaoCid;
            novoCid = busca_cid(indx,cid,cont_cid ,posicaoCid );
            if (novoCid == -1) {
                cout << "\n\nCodigo invalido";
                cout << "\nCodigo Cidade: ";
                cin >> posicaoCid;
                novoCid = busca_cid(indx,cid,cont_cid ,posicaoCid );
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

void lei_ind_cli(indice_cliente idx_cli[], int cont){
    for (int i = 0; i < cont; i++) {
        cout << "\n\nCodigo do Indice " << (i+1) << ": ";
        cin >> idx_cli[i].codigo_cliente;
        cout << "Endereco Fisico na Area de Dados: ";
        cin >> idx_cli[i].ender;

    }
}

int busca_cli ( indice_cliente idx_cli[], cliente cli[], int &cont, int cod){
    int i = 0, f = cont-1;
    int m = (i + f) / 2;
    for (; f >= i && cod != idx_cli[m].codigo_cliente; m = (i + f) / 2){
        if (cod > idx_cli[m].codigo_cliente)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == idx_cli[m].codigo_cliente){
        cout << "\n\nCliente encontrado";
        i = idx_cli[m].ender;
         cout << "\nCodigo do Cliente: " << cli[i].codigo_cliente;
        cout << "\nCodigo da Cidade: " << cli[i].codigo_cidade;
        cout << "\nNome: " << cli[i].nome;
        cout << "\nEndereco: "<< cli[i].endereco;
        return i;
    }
    else
        cout << "\n\n Cliente nao Encontrado";
    return -1;
}

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
}

void busca_inclu_cli ( indice_cliente idx[], cliente cli[], int &cont, int cod){
    int i = 0, f = cont;
    int m = (i + f) / 2;
    for (; f >= i && cod != idx[m].codigo_cliente; m = (i + f) / 2){
        if (cod > idx[m].codigo_cliente)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == idx[m].codigo_cliente){
        cout << "\n\n Cliente ja  Cadastrado - nao pode ser cadastrado novamente";
        i = idx[m].ender;
        cout << "\nCodigo do Cliente: " << cli[i].codigo_cliente;
        cout << "\nNome: " << cli[i].nome;
        cout << "\nEndereco: " << cli[i].endereco;
        cout << "\nCidade: " << cli[i].codigo_cidade;
    }
    else
        inclusao_cli(idx, cli, cont, cod);
    getch();
}

void leitura_venda(venda venda[],indice_cliente indx[],indice_pacote idx[], cliente cli[], pacote paco[], int &cont, int &cont_cli, int &cont_paco ){
    int i=0;
    int posicaoCli;
    int novoCli;
    int posicaoPaco;
    int novoPaco;
    for (int saida = 1; i < 4 && saida !=0 ; i++) {
        cout <<"\n\nCodigo Venda " <<(i+1) <<": ";
        cin >> venda[i].codigo_venda;
        if(venda[i].codigo_venda > 0){
            cout << "\nCodigo Cliente: ";
            cin >> posicaoCli;
            novoCli= busca_cli(indx,cli,cont_cli ,posicaoCli );
            if (novoCli == -1) {
                cout << "\n\nCodigo invalido";
                cout << "\nCodigo Cliente: ";
                cin >> posicaoCli;
                novoCli = busca_cli(indx,cli,cont_cli ,posicaoCli );
            }else{
                venda[i].codigo_cliente = cli[novoCli].codigo_cliente;
            }
            cout << "\nCodigo Pacote: ";
            cin >> posicaoPaco;
            novoPaco= busca_paco(idx,paco,cont_paco ,posicaoPaco );
            if (novoPaco == -1) {
                cout << "\n\nCodigo invalido";
                cout << "\nCodigo Pacote: ";
                cin >> posicaoPaco;
                novoPaco= busca_paco(idx,paco,cont_paco ,posicaoPaco );
            }else{
                venda[i].codigo_pacote = paco[novoPaco].codigo_pacote;
            }

            venda[i].codigo_pacote = paco[novoPaco].codigo_pacote;

            cout << "\nQuantidade de pessoas: ";
            cin >> venda[i].quant_pessoa;

            while (venda[i].quant_pessoa + paco[novoPaco].total_partic > paco[novoPaco].quant_maxPartic) {
                int maxPermitido = paco[novoPaco].quant_maxPartic - paco[novoPaco].total_partic;
                cout << "\nPassou da quantidade maxima permitida. O maximo que pode adicionar e: " << maxPermitido;
                cout << "\nInsira uma nova quantidade de pessoas: ";
                cin >> venda[i].quant_pessoa;
            }

            paco[novoPaco].total_partic += venda[i].quant_pessoa;

            int valor_total = paco[novoPaco].valor_pessoa * venda[i].quant_pessoa;
            cout << "\nValor Total a pagar: " << valor_total;

            paco[novoPaco].status = 0;
        } else {
            saida = 0;
        }
    }
    cont = i-1;
}

void lei_ind_venda(indice_venda idx_venda[], int cont){
    for (int i = 0; i < cont; i++) {
        cout << "\n\nCodigo do Indice " << (i+1) << ": ";
        cin >> idx_venda[i].codigo_venda;
        cout << "Endereco Fisico na Area de Dados: ";
        cin >> idx_venda[i].ender;

    }
}

int busca_venda ( indice_venda idx_venda[], venda vendas[], int &cont, int cod){
    int i = 0, f = cont-1;
    int m = (i + f) / 2;
    for (; f >= i && cod != idx_venda[m].codigo_venda; m = (i + f) / 2){
        if (cod > idx_venda[m].codigo_venda)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == idx_venda[m].codigo_venda){
        cout << "\n\nVenda encontrado";
        i = idx_venda[m].ender;
        cout << "\nCodigo do Venda: " << vendas[i].codigo_venda;
        cout << "\nCodigo Cliente: " << vendas[i].codigo_cliente;
        cout << "\nCodigo Pacote: "<< vendas[i].codigo_pacote;
        cout << "\nQuantidade de pessoa: "<< vendas[i].quant_pessoa;
        cout << "\nValor Total a pagar: "<< vendas[i].valor_total;
        return i;
    }
    else
        cout << "\n\n Venda nao Encontrado";
    return -1;
}

void inclusao_venda(indice_venda idx[], venda vendas[], int &cont, int cod){
    cont++;
    vendas[cont].codigo_venda = cod;

    cout << "\nCodigo Cliente: ";
    cin >> vendas[cont].codigo_cliente;
    cout << "\nCodigo Pacote: ";
    cin >> vendas[cont].codigo_pacote;
    cout << "\nQuantidade de pessoa: ";
    cin >> vendas[cont].quant_pessoa;

    int i;
    for (i = cont -1; idx[i].codigo_venda > cod ; i--) {
        idx[i+1].codigo_venda = idx[i].codigo_venda;
        idx[i+1].ender = idx[i].ender;
    }
    idx[i+1].codigo_venda = cod;
    idx[i+1].ender = cont;
    cout << "\n\nInclusao realizada com Sucesso";
}

void busca_inclu_venda ( indice_venda idx[], venda vendas[], int &cont, int cod){
    int i = 0, f = cont;
    int m = (i + f) / 2;
    for (; f >= i && cod != idx[m].codigo_venda; m = (i + f) / 2){
        if (cod > idx[m].codigo_venda)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == idx[m].codigo_venda){
        cout << "\n\n Venda ja  Cadastrado - nao pode ser cadastrado novamente";
        i = idx[m].ender;
        cout << "\nCodigo do Venda: " << vendas[i].codigo_venda;
        cout << "\nCodigo Cliente: " << vendas[i].codigo_cliente;
        cout << "\nCodigo Pacote: "<< vendas[i].codigo_pacote;
        cout << "\nQuantidade de pessoa: "<< vendas[i].quant_pessoa;
        cout << "\nValor Total: "<< vendas[i].valor_total;
    }
    else
        inclusao_venda(idx, vendas, cont, cod);
    getch();
}

void  buscaCli_excl(indice_cliente idx[],indice_venda idx_venda[], cliente cli[],venda vendas[], int &cont, int cod){
    int i = 0, f = cont;
    int m = (i + f) / 2;
   while (i <= f) {
        m = (i + f) / 2;
        if (cod == idx[m].codigo_cliente) {
            break;
        } else if (cod > idx[m].codigo_cliente) {
            i = m + 1;
        } else {
            f = m - 1;
        }
    }

    if (i > f) {
        cout << "Cliente nao encontrada." << endl;
        return;
    }

    int cli_index = idx[m].ender;

    bool tem_venda = false;
    for (int j = 0; j < cont; j++) {
        if (vendas[idx_venda[j].codigo_venda].codigo_cliente == cli[cli_index].codigo_cliente) {
            tem_venda = true;
            break;
        }
    }

    if (tem_venda) {
        cout << "Nao e possivel excluir o cliente. O guia esta vinculada a uma venda." << endl;
        return;
    }

    if (cli[cli_index].status == 0) {
        cli[cli_index].status = 1;
        cout << "\n\nCliente excluida com sucesso." << endl;
    } else {
        cout << "Client ja esta excluida." << endl;
    }
}

void reorg_cli ( indice_cliente idx[], cliente cli[], int &cont){
    cliente novocli[cont];
    int j=-1;
    for (int k=0; k < cont; k++){
        int i = idx[k].ender;
        if (cli[i].status == 0){
            j++;
            novocli[j] = cli[i];
            idx[j].codigo_cliente = novocli[j].codigo_cliente;
            idx[j].ender = j;
        }
    }
    cont = j+1;
    for (int k = 0; k < cont; k++){
        int i = idx[k].ender;
        cli[k] = novocli [i];
    }
}

void exaustiva_cli (indice_cliente idx[],  cliente cli[], int cont){
    for (int k=0; k < cont; k++){
        int i = idx[k].ender;
        if (cli[i].status == 0){
            cout << "\nEnd Fisico: " << i;
            cout << "\nNome: " << cli[i].nome;
            cout << "\tEndereco: " << cli[i].endereco;
            cout << "\tCidade: " << cli[i].codigo_cidade;
        }
    }
}

void complet_vendido(indice_pacote idx_paco[], pacote paco[], guias guia[], int cont) {
    bool encontrouVendido = false;

    for (int i = 0; i < cont; i++) {
        if (paco[i].total_partic == paco[i].quant_maxPartic) {
            encontrouVendido = true;
            cout << "\nCodigo Pacote: " << paco[i].codigo_pacote;
            cout << "\nDescricao: " << paco[i].descricao;

            for (int j = 0; j < cont; j++) {
                if (guia[j].codigo_guia == paco[i].codigo_guia) {
                    cout << "\nCodigo do Guia: " << guia[j].codigo_guia;
                    break;
                }
            }

            float valor_total_arrecadado = paco[i].total_partic * paco[i].valor_pessoa;
            cout << "\nTotal arrecadado: " << valor_total_arrecadado << endl;
        }
    }

    if (!encontrouVendido) {
        cout << "\nNenhum pacote foi completamente vendido." << endl;
    }
}

int main() {
    paises pais[20]; indice_pais ind_pais[20];
    cidade cidade[20]; indice_cid ind_cid[20];
    guias guia[20];  indice_guia ind_guia[20];
    cliente pessoa[20]; indice_cliente ind_cli[20];
    pacote pacote[20]; indice_pacote ind_paco[20];
    venda venda[20]; indice_venda ind_venda[20];

    int cont_pais;

    cout << "\nLeitura";
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

    cout << "\nLeitura";
    leitura_cid(cidade,ind_pais,pais,cont_cid, cont_pais);
    cout <<"\nLeitura do Indice";
    lei_ind_cid(ind_cid,cont_cid);

    for (int codpesq = 9; codpesq != 0;){
        cout << "\n\nInforme o Codigo do Cidade a ser Buscado (0 para Encerrar): ";
        cin >> codpesq;
        if (codpesq != 0)
            busca_cid( ind_cid, cidade, cont_cid, codpesq);
    }

    int cont_guia, cont_paco;

    cout << "\nLeitura";
    leitura_guia(guia,ind_cid,cidade,cont_guia, cont_cid);
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
            busca_inclu_guia(ind_guia, guia, cont_guia, codpesq);
    }

    cout << "\nLeitura";
    leitura_pacote(pacote,ind_guia,guia,cont_paco, cont_guia);
    cout <<"\nLeitura do Indice";
    lei_ind_paco(ind_paco,cont_paco);

    for(int codpesq = 9; codpesq != 0;){
        cout << "\n\nInforme o Codigo do Pacote a ser Buscado (0 para Encerrar): ";
        cin >> codpesq;
        if (codpesq != 0)
            busca_paco( ind_paco, pacote, cont_paco, codpesq);
    }

    for (int codpesq = 9; codpesq != 0;){
        cout << "\n\nInforme o Codigo do Pacote a ser Inclu do (0 para Encerrar): ";
        cin >> codpesq;
        if (codpesq != 0)
            busca_inclu_paco(ind_paco, pacote, cont_paco, codpesq);
    }

    for (int codpesq = 9; codpesq != 0;){
        cout << "\n\nInforme o Codigo do Guia a ser Excluido (0 para Encerrar): ";
        cin >> codpesq;
        if (codpesq != 0)
            buscaGuia_exclu(ind_guia, guia,ind_paco,pacote, cont_guia, codpesq);
    }
    cout << "\n\nLeitura Exaustiva dos Registros antes da Reorganizacao";
    exaustiva_guia(ind_guia, guia, cont_guia);
    getch();

    reorg_guia(ind_guia, guia, cont_guia);

    cout << "\n\nLeitura Exaustiva dos Registros depois da Reorganizacao";
    exaustiva_guia(ind_guia, guia, cont_guia);
    getch();

    int cont_cli, cont_venda;

    cout << "\nLeitura";
    leitura_cliente(pessoa, ind_cid,cidade,cont_cli, cont_cid);
    cout <<"\nLeitura do Indice";
    lei_ind_cli(ind_cli,cont_cli);

    for (int codpesq = 9; codpesq != 0;){
        cout << "\n\nInforme o Codigo do Cliente a ser Buscado (0 para Encerrar): ";
        cin >> codpesq;
        if (codpesq != 0)
            busca_cli( ind_cli, pessoa, cont_cli, codpesq);
    }

    for (int codpesq = 9; codpesq != 0;){
        cout << "\n\nInforme o Codigo do Cliente a ser Inclu do (0 para Encerrar): ";
        cin >> codpesq;
        if (codpesq != 0)
            busca_inclu_cli(ind_cli, pessoa, cont_cli, codpesq);
    }

    cout << "\nLeitura";
    leitura_venda(venda,ind_cli,ind_paco,pessoa,pacote,cont_venda, cont_cli, cont_paco);
    cout <<"\nLeitura do Indice";
    lei_ind_venda(ind_venda,cont_venda);

    for (int codpesq = 9; codpesq != 0;){
        cout << "\n\nInforme o Codigo do Venda a ser Inclu do (0 para Encerrar): ";
        cin >> codpesq;
        if (codpesq != 0)
            busca_inclu_venda(ind_venda, venda, cont_venda, codpesq);
    }

      float valor_total = 0.0;
    cout << "\n\nVendas Realizadas:\n";

    for (int i = 0; i < cont_venda; i++) {
        cout << "\nVenda " << (i + 1) << ":";
        cout << "\nCodigo Venda: " << venda[i].codigo_venda;
        cout << "\nCodigo Cliente: " << venda[i].codigo_cliente;
        cout << "\nCodigo Pacote: " << venda[i].codigo_pacote;
        cout << "\nQuantidade de Pessoas: " << venda[i].quant_pessoa;
        cout << "\nValor Total da Venda: " << venda[i].valor_total << endl;

        valor_total += venda[i].valor_total;
    }
    cout << "\n\nValor Total de Todas as Vendas: " << valor_total << endl;


    cout << "Pacotes que fecharam as vendas (completamente vendidos):";
    complet_vendido(ind_paco, pacote, guia, cont_paco);

    for (int codpesq = 9; codpesq != 0;){
        cout << "\n\nInforme o Codigo do Cliente a ser Exclu do (0 para Encerrar): ";
        cin >> codpesq;
        if (codpesq != 0)
            buscaCli_excl(ind_cli, ind_venda,pessoa, venda,cont_cli, codpesq);
    }
    cout << "\n\nLeitura Exaustiva dos Registros antes da Reorganizacao";
    exaustiva_cli(ind_cli, pessoa, cont_cli);
    getch();

    reorg_cli( ind_cli, pessoa, cont_cli);

    cout << "\n\nLeitura Exaustiva dos Registros depois da Reorganizacao";
    exaustiva_cli(ind_cli, pessoa, cont_cli);

    return 0;
}

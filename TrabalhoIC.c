#include <stdio.h>
#include <string.h>

struct servico{

    char nome_servico[50];
    char data[50];
    float valor;
    int prazo;
};
struct servico servico[5];

void add(){
    for (int i = 0; i < 5; i++) {
        if (strlen(servico[i].nome_servico) == 0){

            setbuf(stdin,NULL);
            
            printf("Digite o serviço: ");
            fflush(stdin);
            fgets(servico[i].nome_servico,50,stdin);

            printf("Digite a data: ");
            fflush(stdin);
            fgets(servico[i].data,50,stdin);

            printf("Digite o custo: ");
            scanf("%f", &servico[i].valor);

            printf("Digite o prazo: ");
            scanf("%d", &servico[i].prazo);

            printf("\n\n");
            i = 5;
        }
        if (i == 4) {
            printf("Sem espaço para novos serviços!\n\n");
            };
    }

}

void imprimir(){

    int i;
    for ( i = 0; i < 5; i++) {
        if (strlen(servico[i].nome_servico) != 0){
            setbuf(stdin,NULL);
            printf("\nid............................ %d\n", i+1);
            printf("Serviço....................... %s", servico[i].nome_servico);
            printf("Data.......................... %s", servico[i].data);
            printf("Custo......................... %.2f reais\n", servico[i].valor);
            printf("Prazo......................... %d dias\n", servico[i].prazo);
       
        } 
      }
    }
    
void delete() {
    int id;
    imprimir();
    printf("Qual o ID do serviço que voce quer excluir?\n");
    scanf("%d",&id);
    if(id > 0 && id < 5) {
        if(servico[id-1].nome_servico[0] != '\0') {
            servico[id-1].nome_servico[0] = '\0';
            servico[id-1].data[0] = '\0';
            servico[id-1].prazo = 0;
            servico[id-1].valor = 0;
        } else {
            printf("Serviço nao existe!");
        }
    } else printf("Serviço nao existe!");
}

void edit() { 
    int id;
    imprimir();
    printf("\nQual o ID do serviço que voce quer editar?\n");
    scanf("%d",&id);
    if(id > 0 && id < 5) {
        if(servico[id-1].nome_servico[0] != '\0'){  

            setbuf(stdin,NULL);

            printf("Digite o serviço: ");
            fflush(stdin);
            fgets(servico[id-1].nome_servico,50,stdin);

            printf("Digite a data: ");
            fflush(stdin);
            fgets(servico[id-1].data,50,stdin);

            printf("Digite o custo: ");
            scanf("%f", &servico[id-1].valor);

            printf("Digite o prazo: ");
            scanf("%d", &servico[id-1].prazo);

            printf("\n\n");
        } else {
            printf("Serviço não existe!");
             }
        
        } else {
            printf("Serviço não existe!");
         }
    }
int main(){

    int resposta;
    
    while (resposta != 0){ 

        printf("\n###########-Sistema-############\n");
        printf("1-ADICIONAR\n");
        printf("2-IMPRIMIR\n");
        printf("3-EXCLUIR\n");
        printf("4-EDITAR\n");
        printf("0-SAIR\n");

        scanf("%d", &resposta);

        switch (resposta) {
        case 1:
            add();
            break;
        case 2:
            imprimir();
            break;
        case 3:
            delete();
            break;
        case 4:
            edit();
            break;
        case 0:
            resposta = 0;
            break;
        default:
             printf("Opção inválida\n");        
        }
     
    }
       return 0;
}
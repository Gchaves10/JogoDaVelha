// wxWidgets 

// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include <string.h>

int Tabuleiro[3][3];

int jogador; //Qual é o jogador da vez?
int contarRodadas;
int vitoria;//Quem ganhou

void initTabuleiro();
int checkTabuleiro();

void initTabuleiro() 
{
    int i, j;

    jogador= 1;
    contarRodadas = 0;
    vitoria = 0;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            Tabuleiro[i][j] = 0;
        }
    }

}

int checkTabuleiro()
{
    int i, j, p1, p2;//p1 = x e p2 = O

    //Verificando as linhas

    for (i = 0; i < 3; i++) {
        p1 = 0;
        p2 = 0;
        for (j = 0; j < 3; j++) {
            if (Tabuleiro[i][j] == 1)p1++;
            else if (Tabuleiro[i][j] == 2)p2++;
        }
        if (p1 == 3) {
            return 1;
        }
        else if (p2 == 3) {
            return 2;
        }
    }
    //Verificar Colunas
    for (j = 0; j < 3; j++) {
        p1 = 0;
        p2 = 0;
        for(i = 0; i < 3; i++) {
            if (Tabuleiro[i][j] == 1)p1++;
            else if (Tabuleiro[i][j] == 2)p2++;

        }
        if (p1 == 3) {
            return 1;
        }
        else if (p2 == 3) {
            return 2;
        }
        

    }
    //Diagonal principal

    p1 = 0;
    p2 = 0;
    for (i = 0; i < 3; i++) {
        if (Tabuleiro[i][i] == 1)p1++;
        else if (Tabuleiro[i][i] == 2)p2++;
    }
    if (p1 == 3) {
        return 1;
    }
    else if (p2 == 3) {
        return 2;
    }
    //Diagonal Secundária

    p1 = 0;
    p2 = 0;
    j = 2;
    for (i = 0; i < 3; i++) {
        if (Tabuleiro[i][j] == 1)p1++;
        else if (Tabuleiro[i][j] == 2)p2++;
        j--;
    }
    if (p1 == 3) {
        return 1;
    }
    else if (p2 == 3) {
        return 2;
    }
    //Caso Empate
    return 0;


}
class JogodaVelha : public wxApp
{
public:
    virtual bool OnInit();
};

class MainFrame : public wxFrame
{
public:
    MainFrame();
protected:
    wxButton* m_btnUpLeft;
    wxButton* m_btnUpMid;
    wxButton* m_btnUpRight;

    wxButton* m_btnMidLeft;
    wxButton* m_btnMidMid;
    wxButton* m_btnMidRight;

    wxButton* m_btnLowLeft;
    wxButton* m_btnLowMid;
    wxButton* m_btnLowRight;

    wxStatusBar* m_statusBar;

    char m_msgStatusBar[200];

private://métodos

    //Barra do Menu 
    void OnNewGame(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);

    void EnableGrid();
    void DisableGrid();
    void EndGame();
    

    //Botões do jogo Clicados
    void OnBtnUpLeftClick(wxCommandEvent& event);
    void OnBtnUpMidClick(wxCommandEvent& event);
    void OnBtnUpRightClick(wxCommandEvent& event);

    void OnBtnMidLeftClick(wxCommandEvent& event);
    void OnBtnMidMidClick(wxCommandEvent& event);
    void OnBtnMidRightClick(wxCommandEvent& event);

    void OnBtnLowLeftClick(wxCommandEvent& event);
    void OnBtnLowMidClick(wxCommandEvent& event);
    void OnBtnLowRightClick(wxCommandEvent& event);

    //Verifica turno 
    /* Entrada */
    void OnBtnUpLeftEnterWindow(wxCommandEvent& event);
    void OnBtnUpMidEnterWindow(wxCommandEvent& event);
    void OnBtnUpRightEnterWindow(wxCommandEvent& event);

    void OnBtnMidLeftEnterWindow(wxCommandEvent& event);
    void OnBtnMidMidEnterWindow(wxCommandEvent& event);
    void OnBtnMidRightEnterWindow(wxCommandEvent& event);

    void OnBtnLowLeftEnterWindow(wxCommandEvent& event);
    void OnBtnLowMidEnterWindow(wxCommandEvent& event);
    void OnBtnLowRightEnterWindow(wxCommandEvent& event);
    /* Saída */
    void OnBtnUpLeftLeaveWindow(wxCommandEvent& event);
    void OnBtnUpMidLeaveWindow(wxCommandEvent& event);
    void OnBtnUpRightLeaveWindow(wxCommandEvent& event);

    void OnBtnMidLeftLeaveWindow(wxCommandEvent& event);
    void OnBtnMidMidLeaveWindow(wxCommandEvent& event);
    void OnBtnMidRightLeaveWindow(wxCommandEvent& event);

    void OnBtnLowLeftLeaveWindow(wxCommandEvent& event);
    void OnBtnLowMidLeaveWindow(wxCommandEvent& event);
    void OnBtnLowRightLeaveWindow(wxCommandEvent& event);



};

enum
{
    ID_NewGame = 1
};

wxIMPLEMENT_APP(JogodaVelha);
void MainFrame::EnableGrid() 
{
        m_btnUpLeft->Enable();
        m_btnUpMid->Enable();
        m_btnUpRight->Enable();

        m_btnMidLeft->Enable();
        m_btnMidMid->Enable();
        m_btnMidRight->Enable();

        m_btnLowLeft->Enable();
        m_btnLowMid->Enable();
        m_btnLowRight->Enable();

        //Texto dos botões
        m_btnUpLeft->SetLabelText("");
        m_btnUpMid->SetLabelText("");
        m_btnUpRight->SetLabelText("");

        m_btnMidLeft->SetLabelText("");
        m_btnMidMid->SetLabelText("");
        m_btnMidRight->SetLabelText("");

        m_btnLowLeft->SetLabelText("");
        m_btnLowMid->SetLabelText("");
        m_btnLowRight->SetLabelText("");
 }
void MainFrame::DisableGrid()
{
    m_btnUpLeft->Disable();
    m_btnUpMid->Disable();
    m_btnUpRight->Disable();

    m_btnMidLeft->Disable();
    m_btnMidMid->Disable();
    m_btnMidRight->Disable();

    m_btnLowLeft->Disable();
    m_btnLowMid->Disable();
    m_btnLowRight->Disable();

    //Texto dos botões
    m_btnUpLeft->SetLabelText("");
    m_btnUpMid->SetLabelText("");
    m_btnUpRight->SetLabelText("");

    m_btnMidLeft->SetLabelText("");
    m_btnMidMid->SetLabelText("");
    m_btnMidRight->SetLabelText("");

    m_btnLowLeft->SetLabelText("");
    m_btnLowMid->SetLabelText("");
    m_btnLowRight->SetLabelText("");
}

void MainFrame::EndGame() 
{
    char mensagem[200] = "";
    if (vitoria == 0) {
        strcpy(mensagem, "Partida Empatada");
    }
    else {
        if (vitoria == 1) {
            strcpy(mensagem, "X - Jogador 1 Ganhou! ");
        }
        else {
            if (vitoria == 2) {
                strcpy(mensagem, "O - Jogador 2 Ganhou! ");
            }
        }
    }
    strcat(mensagem, "Jogar novamente?");

    if (wxMessageBox(mensagem, "Fim da partida!", wxYES_NO | wxICON_INFORMATION) == wxYES) {
        initTabuleiro();
        EnableGrid();
    }

}

bool JogodaVelha::OnInit()
{
    MainFrame* frame = new MainFrame();
    frame->Show(true);
    initTabuleiro();

    return true;
}

MainFrame::MainFrame()
    : wxFrame(NULL, wxID_ANY, "Jogo da velha")
{
    wxMenu* menuGame = new wxMenu;
    menuGame->Append(ID_NewGame, "Novo Jogo...\tCtrl-N",
        "Começar um novo jogo..");
    menuGame->AppendSeparator();
    menuGame->Append(wxID_EXIT, "Sair","Fechar o jogo..");

    wxMenu* menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT,"Sobre","Informações do jogo..");

    wxMenuBar* menuBar = new wxMenuBar;
    menuBar->Append(menuGame, "&Jogo"); //"append 'pendura' os menus na MenuBar
    menuBar->Append(menuHelp, "&Ajuda");
    wxFont font(48, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);
    SetMenuBar(menuBar);

    wxGridSizer* gBoard = new wxGridSizer(3, 3, 0, 0);
    gBoard->SetMinSize(500, 500);

    //Botões

    /* Up */
    /* UpLeft */
    m_btnUpLeft = new wxButton(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(40, 40), 0);
    m_btnUpLeft->SetFont(font);
    gBoard->Add(m_btnUpLeft, 0, wxALL | wxEXPAND, 5);
    /* Up Mid */
    m_btnUpMid = new wxButton(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(40, 40), 0);
    m_btnUpMid->SetFont(font);
    gBoard->Add(m_btnUpMid, 0, wxALL | wxEXPAND, 5);
    /* Up Right */
    m_btnUpRight = new wxButton(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(40, 40), 0);
    m_btnUpRight->SetFont(font);
    gBoard->Add(m_btnUpRight, 0, wxALL | wxEXPAND, 5);
    /* Mid */
    /*Mid Left*/
    m_btnMidLeft = new wxButton(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(40, 40), 0);
    m_btnMidLeft->SetFont(font);
    gBoard->Add(m_btnMidLeft, 0, wxALL | wxEXPAND, 5);
    /* Mid Mid*/
    m_btnMidMid = new wxButton(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(40, 40), 0);
    m_btnMidMid->SetFont(font);
    gBoard->Add(m_btnMidMid, 0, wxALL | wxEXPAND, 5);
    /*Mid Right*/
    m_btnMidRight = new wxButton(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(40, 40), 0);
    m_btnMidRight->SetFont(font);
    gBoard->Add(m_btnMidRight, 0, wxALL | wxEXPAND, 5);
    /* Low */
    /* Low Left*/
    m_btnLowLeft = new wxButton(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(40, 40), 0);
    m_btnLowLeft->SetFont(font);
    gBoard->Add(m_btnLowLeft, 0, wxALL | wxEXPAND, 5);
    /* Low Mid*/
    m_btnLowMid = new wxButton(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(40, 40), 0);
    m_btnLowMid->SetFont(font);
    gBoard->Add(m_btnLowMid, 0, wxALL | wxEXPAND, 5);
    /* Low Rigth*/
    m_btnLowRight = new wxButton(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(40, 40), 0);
    m_btnLowRight->SetFont(font);
    gBoard->Add(m_btnLowRight, 0, wxALL | wxEXPAND, 5);

    this->SetSizer(gBoard);
    this->Layout();

    m_statusBar = this->CreateStatusBar(1, wxST_SIZEGRIP, wxID_ANY);

    this->Centre(wxBOTH);

    CreateStatusBar();
    DisableGrid();
    SetStatusText("Selecione 'Novo Jogo' para começar uma partida!");

    Bind(wxEVT_MENU, &MainFrame::OnNewGame, this, ID_NewGame);
    Bind(wxEVT_MENU, &MainFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &MainFrame::OnExit, this, wxID_EXIT);

    //Eventos dos botões do jogo
    /* Up */
    m_btnUpLeft->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnBtnUpLeftClick), NULL, this);
    m_btnUpMid->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnBtnUpMidClick), NULL, this);
    m_btnUpRight->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnBtnUpRightClick), NULL, this);
    /* Mid */
    m_btnMidLeft->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnBtnMidLeftClick), NULL, this);
    m_btnMidMid->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnBtnMidMidClick), NULL, this);
    m_btnMidRight->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnBtnMidRightClick), NULL, this);
    /* Low */
    m_btnLowLeft->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnBtnLowLeftClick), NULL, this);
    m_btnLowMid->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnBtnLowMidClick), NULL, this);
    m_btnLowRight->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnBtnLowRightClick), NULL, this);

    //Conector 

    /* Entrada */
    m_btnUpLeft->Connect(wxEVT_ENTER_WINDOW, wxCommandEventHandler(MainFrame::OnBtnUpLeftEnterWindow), NULL, this);
    m_btnUpMid->Connect(wxEVT_ENTER_WINDOW, wxCommandEventHandler(MainFrame::OnBtnUpMidEnterWindow), NULL, this);
    m_btnUpRight->Connect(wxEVT_ENTER_WINDOW, wxCommandEventHandler(MainFrame::OnBtnUpRightEnterWindow), NULL, this);
    /* Mid */
    m_btnMidLeft->Connect(wxEVT_ENTER_WINDOW, wxCommandEventHandler(MainFrame::OnBtnMidLeftEnterWindow), NULL, this);
    m_btnMidMid->Connect(wxEVT_ENTER_WINDOW, wxCommandEventHandler(MainFrame::OnBtnMidMidEnterWindow), NULL, this);
    m_btnMidRight->Connect(wxEVT_ENTER_WINDOW, wxCommandEventHandler(MainFrame::OnBtnMidRightEnterWindow), NULL, this);
    /* Low */
    m_btnLowLeft->Connect(wxEVT_ENTER_WINDOW, wxCommandEventHandler(MainFrame::OnBtnLowLeftEnterWindow), NULL, this);
    m_btnLowMid->Connect(wxEVT_ENTER_WINDOW, wxCommandEventHandler(MainFrame::OnBtnLowMidEnterWindow), NULL, this);
    m_btnLowRight->Connect(wxEVT_ENTER_WINDOW, wxCommandEventHandler(MainFrame::OnBtnLowRightEnterWindow), NULL, this);

    /* Saída */
    m_btnUpLeft->Connect(wxEVT_ENTER_WINDOW, wxCommandEventHandler(MainFrame::OnBtnUpLeftLeaveWindow), NULL, this);
    m_btnUpMid->Connect(wxEVT_ENTER_WINDOW, wxCommandEventHandler(MainFrame::OnBtnUpMidLeaveWindow), NULL, this);
    m_btnUpRight->Connect(wxEVT_ENTER_WINDOW, wxCommandEventHandler(MainFrame::OnBtnUpRightLeaveWindow), NULL, this);
    /* Mid */
    m_btnMidLeft->Connect(wxEVT_ENTER_WINDOW, wxCommandEventHandler(MainFrame::OnBtnMidLeftLeaveWindow), NULL, this);
    m_btnMidMid->Connect(wxEVT_ENTER_WINDOW, wxCommandEventHandler(MainFrame::OnBtnMidMidLeaveWindow), NULL, this);
    m_btnMidRight->Connect(wxEVT_ENTER_WINDOW, wxCommandEventHandler(MainFrame::OnBtnMidRightLeaveWindow), NULL, this);
    /* Low */
    m_btnLowLeft->Connect(wxEVT_ENTER_WINDOW, wxCommandEventHandler(MainFrame::OnBtnLowLeftLeaveWindow), NULL, this);
    m_btnLowMid->Connect(wxEVT_ENTER_WINDOW, wxCommandEventHandler(MainFrame::OnBtnLowMidLeaveWindow), NULL, this);
    m_btnLowRight->Connect(wxEVT_ENTER_WINDOW, wxCommandEventHandler(MainFrame::OnBtnLowRightLeaveWindow), NULL, this);
}
//Lógica dos métodos
void MainFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}

void MainFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("\n\t As regras do Jogo são bem simples.\n Dois jogadores escolhem dois símbolos com que querem jogar.\n Normalmente, usa-se X e O. \n O jogo é realizado em um tabuleiro 3x3 e os espaços serão preenchidos com os símbolos escolhidos. \n O objetivo do jogo é preencher as diagonais ou as horizontais ou as verticais com os símbolos e impedir seu adversário de fazer isso primeiro que você.",
        "Sobre o Jogo da Velha", wxOK | wxICON_INFORMATION);
}

void MainFrame::OnNewGame(wxCommandEvent& event)
{
    EnableGrid();
    initTabuleiro();
    SetStatusText("Turno do jogador 1 (X)");
}

//Botões do tabuleiro "On click"

/*Up*/
void MainFrame::OnBtnUpLeftClick(wxCommandEvent& event) 
{
    if (m_btnUpLeft->IsEnabled()) {
        Tabuleiro[0][0] = jogador;
        m_btnUpLeft->Disable();
        if (jogador == 1) {
            m_btnUpLeft->SetLabelText("X");
            jogador = 2;
        }
        else {
            if (jogador == 2) {
                m_btnUpLeft->SetLabelText("O");
                jogador = 1;
            }
        }
    }
    contarRodadas++;
    vitoria = checkTabuleiro();
    if (vitoria != 0 || contarRodadas >= 9) {
        EndGame();
    }
}
void MainFrame::OnBtnUpMidClick(wxCommandEvent& event)
{
    if (m_btnUpMid->IsEnabled()) {
        Tabuleiro[0][1] = jogador;
        m_btnUpMid->Disable();
        if (jogador == 1) {
            m_btnUpMid->SetLabelText("X");
            jogador = 2;
        }
        else {
            if (jogador == 2) {
                m_btnUpMid->SetLabelText("O");
                jogador = 1;
            }
        }
    }
    contarRodadas++;
    vitoria = checkTabuleiro();
    if (vitoria != 0 || contarRodadas >= 9) {
        EndGame();
    }
}
void MainFrame::OnBtnUpRightClick(wxCommandEvent& event) 
{
    {
        if (m_btnUpRight->IsEnabled()) {
            Tabuleiro[0][2] = jogador;
            m_btnUpRight->Disable();
            if (jogador == 1) {
                m_btnUpRight->SetLabelText("X");
                jogador = 2;
            }
            else {
                if (jogador == 2) {
                    m_btnUpRight->SetLabelText("O");
                    jogador = 1;
                }
            }
        }
        contarRodadas++;
        vitoria = checkTabuleiro();
        if (vitoria != 0 || contarRodadas >= 9) {
            EndGame();
        }
    }

}
/* Mid */
void MainFrame::OnBtnMidLeftClick(wxCommandEvent& event)
{
    if (m_btnMidLeft->IsEnabled()) {
        Tabuleiro[1][0] = jogador;
        m_btnMidLeft->Disable();
        if (jogador == 1) {
            m_btnMidLeft->SetLabelText("X");
            jogador = 2;
        }
        else {
            if (jogador == 2) {
                m_btnMidLeft->SetLabelText("O");
                jogador = 1;
            }
        }
    }
    contarRodadas++;
    vitoria = checkTabuleiro();
    if (vitoria != 0 || contarRodadas >= 9) {
        EndGame();
    }
}
void MainFrame::OnBtnMidMidClick(wxCommandEvent& event) 
{
    if (m_btnMidMid->IsEnabled()) {
        Tabuleiro[1][1] = jogador;
        m_btnMidMid->Disable();
        if (jogador == 1) {
            m_btnMidMid->SetLabelText("X");
            jogador = 2;
        }
        else {
            if (jogador == 2) {
                m_btnMidMid->SetLabelText("O");
                jogador = 1;
            }
        }
    }
    contarRodadas++;
    vitoria = checkTabuleiro();
    if (vitoria != 0 || contarRodadas >= 9) {
        EndGame();
    }
}
void MainFrame::OnBtnMidRightClick(wxCommandEvent& event) 
{
    if (m_btnMidRight->IsEnabled()) {
        Tabuleiro[1][2] = jogador;
        m_btnMidRight->Disable();
        if (jogador == 1) {
            m_btnMidRight->SetLabelText("X");
            jogador = 2;
        }
        else {
            if (jogador == 2) {
                m_btnMidRight->SetLabelText("O");
                jogador = 1;
            }
        }
    }
    contarRodadas++;
    vitoria = checkTabuleiro();
    if (vitoria != 0 || contarRodadas >= 9) {
        EndGame();
    }
}
/* Low */
void MainFrame::OnBtnLowLeftClick(wxCommandEvent& event) 
{
    if (m_btnLowLeft->IsEnabled()) {
        Tabuleiro[2][0] = jogador;
        m_btnLowLeft->Disable();
        if (jogador == 1) {
            m_btnLowLeft->SetLabelText("X");
            jogador = 2;
        }
        else {
            if (jogador == 2) {
                m_btnLowLeft->SetLabelText("O");
                jogador = 1;
            }
        }
    }
    contarRodadas++;
    vitoria = checkTabuleiro();
    if (vitoria != 0 || contarRodadas >= 9) {
        EndGame();
    }
}
void MainFrame::OnBtnLowMidClick(wxCommandEvent& event) 
{
    if (m_btnLowMid->IsEnabled()) {
        Tabuleiro[2][1] = jogador;
        m_btnLowMid->Disable();
        if (jogador == 1) {
            m_btnLowMid->SetLabelText("X");
            jogador = 2;
        }
        else {
            if (jogador == 2) {
                m_btnLowMid->SetLabelText("O");
                jogador = 1;
            }
        }
    }
    contarRodadas++;
    vitoria = checkTabuleiro();
    if (vitoria != 0 || contarRodadas >= 9) {
        EndGame();
    }
}
void MainFrame::OnBtnLowRightClick(wxCommandEvent& event) 
{
    if (m_btnLowRight->IsEnabled()) {
        Tabuleiro[2][2] = jogador;
        m_btnLowRight->Disable();
        if (jogador == 1) {
            m_btnLowRight->SetLabelText("X");
            jogador = 2;
        }
        else {
            if (jogador == 2) {
                m_btnLowRight->SetLabelText("O");
                jogador = 1;
            }
        }
    }
    contarRodadas++;
    vitoria = checkTabuleiro();
    if (vitoria != 0 || contarRodadas >= 9) {
        EndGame();
    }
}

//Verifica turno 
    /* Entrada */
void MainFrame::OnBtnUpLeftEnterWindow(wxCommandEvent& event) 
{
    if (m_btnUpLeft->IsEnabled()) {
        strcpy(m_msgStatusBar, "");
        strcpy(m_msgStatusBar, "Clique aqui para marcar  ");
        if (jogador == 1) {
            strcat(m_msgStatusBar, "(X)");
        }
        else {
            if (jogador == 2) {
                strcat(m_msgStatusBar, "(O)");
            }
        }
    }
    SetStatusText(m_msgStatusBar);
}
void MainFrame::OnBtnUpMidEnterWindow(wxCommandEvent& event)
{
    if (m_btnUpMid->IsEnabled()) {
        strcpy(m_msgStatusBar, "");
        strcpy(m_msgStatusBar, "Clique aqui para marcar  ");
        if (jogador == 1) {
            strcat(m_msgStatusBar, "(X)");
        }
        else {
            if (jogador == 2) {
                strcat(m_msgStatusBar, "(O)");
            }
        }
    }
    SetStatusText(m_msgStatusBar);
}
void MainFrame::OnBtnUpRightEnterWindow(wxCommandEvent& event)
{
    if (m_btnUpRight->IsEnabled()) {
        strcpy(m_msgStatusBar, "");
        strcpy(m_msgStatusBar, "Clique aqui para marcar  ");
        if (jogador == 1) {
            strcat(m_msgStatusBar, "(X)");
        }
        else {
            if (jogador == 2) {
                strcat(m_msgStatusBar, "(O)");
            }
        }
    }
    SetStatusText(m_msgStatusBar);
}

void MainFrame::OnBtnMidLeftEnterWindow(wxCommandEvent& event)
{
    if (m_btnMidLeft->IsEnabled()) {
        strcpy(m_msgStatusBar, "");
        strcpy(m_msgStatusBar, "Clique aqui para marcar  ");
        if (jogador == 1) {
            strcat(m_msgStatusBar, "(X)");
        }
        else {
            if (jogador == 2) {
                strcat(m_msgStatusBar, "(O)");
            }
        }
    }
    SetStatusText(m_msgStatusBar);
}
void MainFrame::OnBtnMidMidEnterWindow(wxCommandEvent& event)
{
    if (m_btnMidMid->IsEnabled()) {
        strcpy(m_msgStatusBar, "");
        strcpy(m_msgStatusBar, "Clique aqui para marcar  ");
        if (jogador == 1) {
            strcat(m_msgStatusBar, "(X)");
        }
        else {
            if (jogador == 2) {
                strcat(m_msgStatusBar, "(O)");
            }
        }
    }
    SetStatusText(m_msgStatusBar);
}
void MainFrame::OnBtnMidRightEnterWindow(wxCommandEvent& event)
{
    if (m_btnMidRight->IsEnabled()) {
        strcpy(m_msgStatusBar, "");
        strcpy(m_msgStatusBar, "Clique aqui para marcar  ");
        if (jogador == 1) {
            strcat(m_msgStatusBar, "(X)");
        }
        else {
            if (jogador == 2) {
                strcat(m_msgStatusBar, "(O)");
            }
        }
    }
    SetStatusText(m_msgStatusBar);
}


void MainFrame::OnBtnLowLeftEnterWindow(wxCommandEvent& event)
{
    if (m_btnLowLeft->IsEnabled()) {
        strcpy(m_msgStatusBar, "");
        strcpy(m_msgStatusBar, "Clique aqui para marcar  ");
        if (jogador == 1) {
            strcat(m_msgStatusBar, "(X)");
        }
        else {
            if (jogador == 2) {
                strcat(m_msgStatusBar, "(O)");
            }
        }
    }
    SetStatusText(m_msgStatusBar);
}
void MainFrame::OnBtnLowMidEnterWindow(wxCommandEvent& event)
{
    if (m_btnLowMid->IsEnabled()) {
        strcpy(m_msgStatusBar, "");
        strcpy(m_msgStatusBar, "Clique aqui para marcar  ");
        if (jogador == 1) {
            strcat(m_msgStatusBar, "(X)");
        }
        else {
            if (jogador == 2) {
                strcat(m_msgStatusBar, "(O)");
            }
        }
    }
    SetStatusText(m_msgStatusBar);
}
void MainFrame::OnBtnLowRightEnterWindow(wxCommandEvent& event)
{
    if (m_btnLowRight->IsEnabled()) {
        strcpy(m_msgStatusBar, "");
        strcpy(m_msgStatusBar, "Clique aqui para marcar  ");
        if (jogador == 1) {
            strcat(m_msgStatusBar, "(X)");
        }
        else {
            if (jogador == 2) {
                strcat(m_msgStatusBar, "(O)");
            }
        }
    }
    SetStatusText(m_msgStatusBar);
}
/* Saída */
void MainFrame::OnBtnUpLeftLeaveWindow(wxCommandEvent& event)
{
    if (m_btnUpLeft->IsEnabled()) {
        strcpy(m_msgStatusBar, "");
        strcpy(m_msgStatusBar, "Clique aqui para marcar  ");
        if (jogador == 1) {
            strcat(m_msgStatusBar, "(X)");
        }
        else {
            if (jogador == 2) {
                strcat(m_msgStatusBar, "(O)");
            }
        }
    }
    SetStatusText(m_msgStatusBar);
}
void MainFrame::OnBtnUpMidLeaveWindow(wxCommandEvent& event)
{
    if (m_btnUpMid->IsEnabled()) {
        strcpy(m_msgStatusBar, "");
        strcpy(m_msgStatusBar, "Clique aqui para marcar  ");
        if (jogador == 1) {
            strcat(m_msgStatusBar, "(X)");
        }
        else {
            if (jogador == 2) {
                strcat(m_msgStatusBar, "(O)");
            }
        }
    }
    SetStatusText(m_msgStatusBar);
}
void MainFrame::OnBtnUpRightLeaveWindow(wxCommandEvent& event)
{
    if (m_btnUpRight->IsEnabled()) {
        strcpy(m_msgStatusBar, "");
        strcpy(m_msgStatusBar, "Clique aqui para marcar  ");
        if (jogador == 1) {
            strcat(m_msgStatusBar, "(X)");
        }
        else {
            if (jogador == 2) {
                strcat(m_msgStatusBar, "(O)");
            }
        }
    }
    SetStatusText(m_msgStatusBar);
}
void MainFrame::OnBtnMidLeftLeaveWindow(wxCommandEvent& event)
{
    if (m_btnMidLeft->IsEnabled()) {
        strcpy(m_msgStatusBar, "");
        strcpy(m_msgStatusBar, "Clique aqui para marcar  ");
        if (jogador == 1) {
            strcat(m_msgStatusBar, "(X)");
        }
        else {
            if (jogador == 2) {
                strcat(m_msgStatusBar, "(O)");
            }
        }
    }
    SetStatusText(m_msgStatusBar);
}
void MainFrame::OnBtnMidMidLeaveWindow(wxCommandEvent& event)
{
    if (m_btnMidLeft->IsEnabled()) {
        strcpy(m_msgStatusBar, "");
        strcpy(m_msgStatusBar, "Clique aqui para marcar  ");
        if (jogador == 1) {
            strcat(m_msgStatusBar, "(X)");
        }
        else {
            if (jogador == 2) {
                strcat(m_msgStatusBar, "(O)");
            }
        }
    }
    SetStatusText(m_msgStatusBar);
}
void MainFrame::OnBtnMidRightLeaveWindow(wxCommandEvent& event)
{
    if (m_btnMidRight->IsEnabled()) {
        strcpy(m_msgStatusBar, "");
        strcpy(m_msgStatusBar, "Clique aqui para marcar  ");
        if (jogador == 1) {
            strcat(m_msgStatusBar, "(X)");
        }
        else {
            if (jogador == 2) {
                strcat(m_msgStatusBar, "(O)");
            }
        }
    }
    SetStatusText(m_msgStatusBar);
}

void MainFrame::OnBtnLowLeftLeaveWindow(wxCommandEvent& event)
{
    if (m_btnLowLeft->IsEnabled()) {
        strcpy(m_msgStatusBar, "");
        strcpy(m_msgStatusBar, "Clique aqui para marcar  ");
        if (jogador == 1) {
            strcat(m_msgStatusBar, "(X)");
        }
        else {
            if (jogador == 2) {
                strcat(m_msgStatusBar, "(O)");
            }
        }
    }
    SetStatusText(m_msgStatusBar);
}
void MainFrame::OnBtnLowMidLeaveWindow(wxCommandEvent& event)
{
    if (m_btnLowMid->IsEnabled()) {
        strcpy(m_msgStatusBar, "");
        strcpy(m_msgStatusBar, "Clique aqui para marcar  ");
        if (jogador == 1) {
            strcat(m_msgStatusBar, "(X)");
        }
        else {
            if (jogador == 2) {
                strcat(m_msgStatusBar, "(O)");
            }
        }
    }
    SetStatusText(m_msgStatusBar);
}
void MainFrame::OnBtnLowRightLeaveWindow(wxCommandEvent& event)
{
    if (m_btnLowRight->IsEnabled()) {
        strcpy(m_msgStatusBar, "");
        strcpy(m_msgStatusBar, "Clique aqui para marcar  ");
        if (jogador == 1) {
            strcat(m_msgStatusBar, "(X)");
        }
        else {
            if (jogador == 2) {
                strcat(m_msgStatusBar, "(O)");
            }
        }
    }
    SetStatusText(m_msgStatusBar);
}

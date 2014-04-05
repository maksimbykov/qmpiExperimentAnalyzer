#include "runexperimentdialog.h"
#include <QGridLayout>
#include <QFileDialog>

RunExperimentDialog::RunExperimentDialog()
    :QDialog()
{
    this->setWindowTitle("Run experiment");
    resize(450,200);

    m_mpichAppLine  = new QLineEdit(this);
    m_mpichAppLine->setPlaceholderText("Select mpich.exe path");
    m_expAppLine    = new QLineEdit(this);
    m_expAppLine->setPlaceholderText("Select path of experiment to run");
    m_freqTxtLine   = new QLineEdit(this);
    m_freqTxtLine->setPlaceholderText("Select frequency settings text document");
    m_lengthTxtLine = new QLineEdit(this);
    m_lengthTxtLine->setPlaceholderText("Select message length settings text document");

    m_mpichAppButton  = new QPushButton("Open file", this);
    m_expAppButton    = new QPushButton("Open file", this);
    m_freqTxtButton   = new QPushButton("Open file", this);
    m_lengthTxtButton = new QPushButton("Open file", this);
    m_runButton       = new QPushButton("Run", this);

    QGridLayout* layout = new QGridLayout();

    layout->addWidget(m_mpichAppLine,   0,0);
    layout->addWidget(m_mpichAppButton, 0,1);
    layout->addWidget(m_expAppLine,     1,0);
    layout->addWidget(m_expAppButton,   1,1);
    layout->addWidget(m_freqTxtLine,    2,0);
    layout->addWidget(m_freqTxtButton,  2,1);
    layout->addWidget(m_lengthTxtLine,  3,0);
    layout->addWidget(m_lengthTxtButton,3,1);
    layout->addWidget(m_runButton,      4,0);

    setLayout(layout);

    m_runButton->setFocus();

    connect(m_mpichAppButton,  SIGNAL(clicked()), SLOT(openMpich()));
    connect(m_expAppButton,    SIGNAL(clicked()), SLOT(openExperiment()));
    connect(m_freqTxtButton,   SIGNAL(clicked()), SLOT(openFrequency()));
    connect(m_lengthTxtButton, SIGNAL(clicked()), SLOT(openLength()));
    connect(m_runButton,       SIGNAL(clicked()), SLOT(run()));
}

void RunExperimentDialog::openMpich()
{
    QString fileName = QFileDialog::getOpenFileName( this, tr("Open File"), "", tr("Files (*.exe)") );

    if ( !fileName.isNull() )
    {
        m_mpichAppLine->setText(fileName);
    }
}

void RunExperimentDialog::openExperiment()
{
    QString fileName = QFileDialog::getOpenFileName( this, tr("Open File"), "", tr("Files (*.exe)") );

    if ( !fileName.isNull() )
    {
        m_expAppLine->setText(fileName);
    }
}

void RunExperimentDialog::openFrequency()
{
    QString fileName = QFileDialog::getOpenFileName( this, tr("Open File"), "", tr("Files (*.txt)") );

    if ( !fileName.isNull() )
    {
        m_freqTxtLine->setText(fileName);
    }
}

void RunExperimentDialog::openLength()
{
    QString fileName = QFileDialog::getOpenFileName( this, tr("Open File"), "", tr("Files (*.exe)") );

    if ( !fileName.isNull() )
    {
        m_lengthTxtLine->setText(fileName);
    }
}

void RunExperimentDialog::run()
{

}

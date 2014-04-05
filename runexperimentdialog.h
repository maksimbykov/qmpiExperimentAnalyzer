#ifndef RUNEXPERIMENTDIALOG_H
#define RUNEXPERIMENTDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>

class RunExperimentDialog : public QDialog
{
    Q_OBJECT

    QLineEdit* m_mpichAppLine;
    QLineEdit* m_expAppLine;
    QLineEdit* m_freqTxtLine;
    QLineEdit* m_lengthTxtLine;

    QPushButton* m_mpichAppButton;
    QPushButton* m_expAppButton;
    QPushButton* m_freqTxtButton;
    QPushButton* m_lengthTxtButton;

    QPushButton* m_runButton;

    QString m_runCommand;

    //TODO: progress bar
public:
    RunExperimentDialog();

private slots:
    void openMpich();
    void openExperiment();
    void openFrequency();
    void openLength();
    void run();
};

#endif // RUNEXPERIMENTDIALOG_H

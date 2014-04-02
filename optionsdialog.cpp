#include "optionsdialog.h"
#include <QVBoxLayout>
#include <QFrame>

#include <QLabel>

OptionsDialog::OptionsDialog(QVector<bool> *pResults, int *x, int *y)
    :QDialog(), m_pResults(pResults), m_pXAxis(x), m_pYAxis(y)
{
    this->setWindowTitle("Options");
    QVBoxLayout *layout = new QVBoxLayout(this);

    QLabel *firstLabel = new QLabel("Choose plot to show", this);
    firstLabel->setAlignment(Qt::AlignBottom | Qt::AlignLeft);
    layout->addWidget(firstLabel);

    for ( int i=0; i < m_pResults->size(); i++)
    {
        QString title("From ");
        title.append(QString::number(i));
        m_checkBoxes.push_back(new QCheckBox(title));
        if ( true == (*m_pResults)[i] )
        {
            m_checkBoxes[i]->setChecked(true);
        }

        layout->addWidget(m_checkBoxes.last());
    }

    QFrame* line = new QFrame(this);
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);
    layout->addWidget(line);

    QLabel *xAxisLabel = new QLabel("x axis", this);
    xAxisLabel->setAlignment(Qt::AlignBottom | Qt::AlignLeft);
    layout->addWidget(xAxisLabel);

    m_xCombo.addItem(tr("Local time"));
    m_xCombo.addItem(tr("Local counter"));
    m_xCombo.addItem(tr("Time spent"));
    m_xCombo.addItem(tr("Message size"));
    m_xCombo.addItem(tr("Frequency"));
    m_xCombo.setCurrentIndex(*m_pXAxis);
    layout->addWidget(&m_xCombo);

    QLabel *yAxisLabel = new QLabel("y axis", this);
    yAxisLabel->setAlignment(Qt::AlignBottom | Qt::AlignLeft);
    layout->addWidget(yAxisLabel);

    m_yCombo.addItem(tr("Local time"));
    m_yCombo.addItem(tr("Local counter"));
    m_yCombo.addItem(tr("Time spent"));
    m_yCombo.addItem(tr("Message size"));
    m_yCombo.addItem(tr("Frequency"));
    m_yCombo.setCurrentIndex(*m_pYAxis);
    layout->addWidget(&m_yCombo);

    this->setLayout(layout);
    this->setFixedWidth(300);
}

OptionsDialog::~OptionsDialog()
{
    for ( int i=0; i < m_pResults->size(); i++ )
    {
        if ( m_checkBoxes[i]->isChecked() )
            (*m_pResults)[i] = true;
        else
            (*m_pResults)[i] = false;
    }

    *m_pXAxis = m_xCombo.currentIndex();
    *m_pYAxis = m_yCombo.currentIndex();
}

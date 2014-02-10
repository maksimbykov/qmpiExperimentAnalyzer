#include "experiment_analyzer.h"
#include <QFile>
#include <QDebug>

void ExperimentAnalyzer::readInputFile()
{
    QFile file("C:/Programs/res.xml");
    QString elementText;
    experiment_t::Iterator rankIterator = m_experimentResults.begin();
    QMap<int, QVector<Result> >::Iterator toIterator;

    if ( !file.open(QFile::ReadOnly | QFile::Text) )
    {
        qDebug() << "Cannot open file";
    }
    else
    {
        m_xmlReader.setDevice(&file);

        while ( m_xmlReader.readNextStartElement() )
        {
            if ( "rank" == m_xmlReader.name() )
            {
                elementText = m_xmlReader.readElementText();
                rankIterator = m_experimentResults.insert(elementText.toInt(),
                                                          QMap<int, QVector<Result> >());
            }
            else if ( "to" == m_xmlReader.name() )
            {
                elementText = m_xmlReader.readElementText();
                toIterator = rankIterator.value().insert(elementText.toInt(), QVector<Result>());
            }
            else if ( "send_result" == m_xmlReader.name() )
            {
                toIterator.value().push_back(Result(0.0f,0));
            }
            else if ( "time_send" == m_xmlReader.name() )
            {
                elementText = m_xmlReader.readElementText();
                toIterator.value().last().m_time = elementText.toFloat();
            }
            else if ( "bytes" == m_xmlReader.name() )
            {
                elementText = m_xmlReader.readElementText();
                toIterator.value().last().m_size = elementText.toInt();
            }
            else
            {
                //m_xmlReader.readElementText();
            }
        }
    }
}

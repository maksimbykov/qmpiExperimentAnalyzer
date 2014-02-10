#ifndef EXPERIMENT_ANALYZER_H
#define EXPERIMENT_ANALYZER_H

#include <QXmlStreamReader>
#include <QVector>
#include <QMap>

struct Result
{
    float m_time;
    int   m_size;

    Result( float t = 0.0f, int s = 0 )
        :m_time(t), m_size(s){}
};

class ExperimentAnalyzer
{
    typedef QMap<int, QMap<int, QVector<Result> > > experiment_t;

    QXmlStreamReader m_xmlReader;

    experiment_t m_experimentResults;

public:
    ExperimentAnalyzer(){}
    virtual ~ExperimentAnalyzer(){}

    void readInputFile();
    void drawResults();
};


#endif // EXPERIMENT_ANALYZER_H

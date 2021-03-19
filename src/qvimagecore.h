﻿#ifndef QVIMAGECORE_H
#define QVIMAGECORE_H

#include <QObject>
#include <QImageReader>
#include <QPixmap>
#include <QMovie>
#include <QFileInfo>
#include <QFutureWatcher>
#include <QTimer>
#include <QCache>

class QVImageCore : public QObject
{
    Q_OBJECT

public:
    enum class ScaleMode
    {
       normal,
       width,
       height
    };
    Q_ENUM(ScaleMode)

    struct QVFileDetails
    {
        QFileInfo fileInfo;
        QFileInfoList folderFileInfoList;
        bool isLoadRequested = false;
        bool isPixmapLoaded = false;
        bool isMovieLoaded = false;
        int loadedIndexInFolder = -1;
        QSize baseImageSize;
        QSize loadedPixmapSize;
    };

    struct QVReadImageInfo
    {
        QImage readImage;
        QFileInfo readFileInfo;
        QSize size;
    };

    explicit QVImageCore(QObject *parent = nullptr);

    void loadFile(const QString &fileName);
    QVReadImageInfo readFile(const QString &fileName, bool forCache = false);
    void postRead(const QVReadImageInfo &readImageAndFileInfo);
    void postLoad();
    void closeImage();
    void updateFolderInfo();
    void requestCaching();
    void requestCachingFile(const QString &filePath);
    void addToCache(const QVReadImageInfo &readImageAndFileInfo);

    void settingsUpdated();

    void jumpToNextFrame();
    void setPaused(bool desiredState);
    void setSpeed(int desiredSpeed);

    void rotateImage(int rotation);
    QImage matchCurrentRotation(const QImage &imageToRotate);
    QPixmap matchCurrentRotation(const QPixmap &pixmapToRotate);

    QPixmap scaleExpensively(const int desiredWidth, const int desiredHeight, const ScaleMode mode = ScaleMode::normal);
    QPixmap scaleExpensively(const QSize desiredSize, const ScaleMode mode = ScaleMode::normal);

    //returned const reference is read-only
    const QPixmap& getLoadedPixmap() const {return loadedPixmap; }
    const QMovie& getLoadedMovie() const {return loadedMovie; }
    const QVFileDetails& getCurrentFileDetails() const {return currentFileDetails; }
    int getCurrentRotation() const {return currentRotation; }

signals:
    void animatedFrameChanged(QRect rect);

    void updateLoadedPixmapItem();

    void fileChanged();

    void readError(int errorNum, const QString &errorString, const QString &fileName);

private:
    QPixmap loadedPixmap;
    QMovie loadedMovie;

    QVFileDetails currentFileDetails;
    int currentRotation;

    QFutureWatcher<QVReadImageInfo> loadFutureWatcher;

    bool justLoadedFromCache;

    bool isLoopFoldersEnabled;
    int preloadingMode;
    int sortMode;
    bool sortDescending;

    QPair<QString, uint> lastDirInfo;
    unsigned randomSortSeed;

    QStringList lastFilesPreloaded;

    QTimer *fileChangeRateTimer;

    int largestDimension;
};

#endif // QVIMAGECORE_H

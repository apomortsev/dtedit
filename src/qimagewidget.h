////////////////////////////////////////////////////////////////////////////////
// (c) 2013 Rolf Meyerhoff. All rights reserved.
////////////////////////////////////////////////////////////////////////////////
///\file    qimagewidget.h
///\brief   Image based widget definition.
///\author  Rolf Meyerhoff (rm@matrix44.de)
///\version 1.0
////////////////////////////////////////////////////////////////////////////////
///\par License:
/// This program is free software: you can redistribute it and/or modify it
/// under the terms of the GNU General Public License as published by the Free
/// Software Foundation, either version 2 of the License, or (at your option)
/// any later version.
///\par
/// This program is distributed in the hope that it will be useful, but WITHOUT
/// ANY WARRANTY; without even  the implied warranty of MERCHANTABILITY or
/// FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
/// more details.
///\par
/// You should have received a copy of the GNU General Public License along with
/// this program; see the file COPYING. If not, see http://www.gnu.org/licenses/
/// or write to the Free Software Foundation, Inc., 51 Franklin Street, Fifth
/// Floor, Boston, MA 02110-1301, USA.
////////////////////////////////////////////////////////////////////////////////
#ifndef __QIMAGEWIDGET_H_INCLUDED__
#define __QIMAGEWIDGET_H_INCLUDED__

#include <QtGui>
#if QT_VERSION >= 0x050000
#include <QtWidgets>
#endif

////////////////////////////////////////////////////////////////////////////////
///\class QImageWidget qimagewidget.h
///\brief Abstract base class for all image based widgets.
////////////////////////////////////////////////////////////////////////////////
class QImageWidget :
  public QWidget
{
  Q_OBJECT// Qt magic...

public:

  //////////////////////////////////////////////////////////////////////////////
  // QImageWidget::QImageWidget()
  //////////////////////////////////////////////////////////////////////////////
  ///\brief   Default constructor of this widget.
  ///\param   [in] parent: Parent window for this widget.
  ///\remarks Just initializes the members.
  //////////////////////////////////////////////////////////////////////////////
  QImageWidget(QWidget* parent = 0) :
    QWidget(parent)
  {
    // Optimize performance:
    setAttribute(Qt::WA_OpaquePaintEvent, true);
    setAttribute(Qt::WA_NoSystemBackground, true);
  }

  //////////////////////////////////////////////////////////////////////////////
  // QImageWidget::~QImageWidget()
  //////////////////////////////////////////////////////////////////////////////
  ///\brief   Destructor of this window.
  ///\remarks Cleans up used resources.
  //////////////////////////////////////////////////////////////////////////////
  virtual ~QImageWidget()
  {
    // Nothing to do here.
  }

  //////////////////////////////////////////////////////////////////////////////
  // QImageWidget::image()
  //////////////////////////////////////////////////////////////////////////////
  ///\brief   Get accessor for the Image property.
  ///\return  The current image.
  ///\remarks This image is the source for the widget.
  //////////////////////////////////////////////////////////////////////////////
  const QPixmap& image() const
  {
    // Return our image:
    return m_image;
  }

  //////////////////////////////////////////////////////////////////////////////
  // QImageWidget::setImage()
  //////////////////////////////////////////////////////////////////////////////
  ///\brief   Set accessor for the Image property.
  ///\param   [in] newImage: The new image.
  ///\remarks This image is the source for the widget.
  //////////////////////////////////////////////////////////////////////////////
  void setImage(const QPixmap& newImage)
  {
    // Set new image:
    m_image = newImage;

    // Force redraw:
    update();
  }

  //////////////////////////////////////////////////////////////////////////////
  // QImageWidget::disabledImage()
  //////////////////////////////////////////////////////////////////////////////
  ///\brief   Get accessor for the DisabledImage property.
  ///\return  The current disabled state image.
  ///\remarks This image is shown when the widget is disabled. It should have
  ///         the same size as one frame of the knob movie image.
  //////////////////////////////////////////////////////////////////////////////
  const QPixmap& disabledImage() const
  {
    // Return our image:
    return m_disabledImage;
  }

  //////////////////////////////////////////////////////////////////////////////
  // QImageWidget::setDisabledImage()
  //////////////////////////////////////////////////////////////////////////////
  ///\brief   Set accessor for the DisabledImage property.
  ///\param   [in] newImage: The new image.
  ///\remarks This image is shown when the widget is disabled. It should have
  ///         the same size as one frame of the knob movie image.
  //////////////////////////////////////////////////////////////////////////////
  void setDisabledImage(const QPixmap& newImage)
  {
    // Set new image:
    m_disabledImage = newImage;

    // Force redraw:
    update();
  }

  //////////////////////////////////////////////////////////////////////////////
  // QImageWidget::tag()
  //////////////////////////////////////////////////////////////////////////////
  ///\brief   Get accessor for the Tag property.
  ///\return  The currently stored user value.
  ///\remarks This tag is an arbitrary user defined value.
  //////////////////////////////////////////////////////////////////////////////
  int tag() const
  {
    // Return current tag:
    return m_tag;
  }

  //////////////////////////////////////////////////////////////////////////////
  // QImageWidget::setTag()
  //////////////////////////////////////////////////////////////////////////////
  ///\brief   Set accessor for the Tag property.
  ///\param   [in] newTag: The new user defined value.
  ///\remarks This tag is an arbitrary user defined value.
  //////////////////////////////////////////////////////////////////////////////
  void setTag(const int newTag)
  {
    // Set new tag:
    m_tag = newTag;
  }

protected:

  //////////////////////////////////////////////////////////////////////////////
  // QImageToggle::paintEvent()
  //////////////////////////////////////////////////////////////////////////////
  ///\brief   Handler for the paint signal.
  ///\param   [in] event: Provides further details about the event.
  //////////////////////////////////////////////////////////////////////////////
  void paintEvent(QPaintEvent* event)
  {
    // Do we have a movie?
    if (image().isNull())
    {
      // Let the base class do the painting:
      QWidget::paintEvent(event);
      return;
    }

    // Draw the movie:
    QPainter qp(this);
    drawWidget(qp);
  }

  //////////////////////////////////////////////////////////////////////////////
  // QImageToggle::changeEvent()
  //////////////////////////////////////////////////////////////////////////////
  ///\brief   Handler for general state change signals.
  ///\param   [in] event: Provides further details about the event.
  //////////////////////////////////////////////////////////////////////////////
  void changeEvent(QEvent* event)
  {
    // Base handling:
    QWidget::changeEvent(event);

    // Redraw if the enabled state changed:
    if (event->type() == QEvent::EnabledChange)
      update();
  }

  //////////////////////////////////////////////////////////////////////////////
  // QImageWidget::drawWidget()
  //////////////////////////////////////////////////////////////////////////////
  ///\brief Internal helper that paints the actual widget.
  ///\param [in] qp: Device context to use.
  //////////////////////////////////////////////////////////////////////////////
  virtual void drawWidget(QPainter& qp) = 0;

private:

  //////////////////////////////////////////////////////////////////////////////
  // Member:
  QPixmap m_image;         ///\> The knob movie image strip.
  QPixmap m_disabledImage; ///\> The knob movie image strip.
  int     m_tag;           ///\> User defined value.
};

#endif // __QIMAGEWIDGET_H_INCLUDED__
///////////////////////////////// End of File //////////////////////////////////
